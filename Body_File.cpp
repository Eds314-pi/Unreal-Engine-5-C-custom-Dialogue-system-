#include "ReadFromFile.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "HAL/PlatformFileManager.h"
#include "Misc/FileHelper.h"

TArray<FLinearColor> ColorPicker(int limit, FScript Conversation, string file, int skip) {
	ifstream in_file;
	in_file.open(file);
	int* ColorComp = new int[limit * 3];
	string line;
	for (int i = 0;i < skip+1;i++)
	{
		std::getline(in_file, line, '\n');
		
	}
	//ensures it goes to 15
	for (int i = 1;i < (limit * 3)+1;i++) {
		if (i % 3 != 0 ||i==0)
		{
			std::getline(in_file, line, ',');
			ColorComp[i] = stoi(line);
		}
		else {
			std::getline(in_file, line, '\n');
			ColorComp[i] = stoi(line);
		}
		
	}

	for (int i = 0;i < limit;i++) {
 		Conversation.Color[i] = FLinearColor((float)ColorComp[(i*3)+1], (float)ColorComp[(i*3) + 2], (float)ColorComp[(i*3) + 3], (float)1);
		
	}

	delete ColorComp;
	return Conversation.Color;
}

TArray<int> SizePicker(int limit, FScript Conversation, string file, int skip) {
	ifstream in_file;
	in_file.open(file);
	string line;
	if (in_file.is_open())
	{
			for (int i = 0;i < skip + 1;i++)
			{
				std::getline(in_file, line, '\n');
			}
			for (int i = 0;i < limit;i++)
			{
				std::getline(in_file, line, '\n');
				int x = stoi(line);
				Conversation.Size[i] = x;
				cout << x << endl;
			}
	}
	
	return Conversation.Size;
}

FString UReadFromFile::ReadStringFromFile(FString Filepath, bool& bOutSuccess, FString& OutInfoMessage) {
//Checks if File exists
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*Filepath)) {
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Read String From File Failed cause it doesn't exist '%s'"), *Filepath);
		return "";
	}
	FString ReString = "";
//Checks if File is a readable file
	if (!FFileHelper::LoadFileToString(ReString, *Filepath)) {
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("ReadStringFromFIleFailed-Not A text file '%s'"), *Filepath);
		return "";
	}
//returns the ENTIRE file	
	return ReString;

}

FScript UReadFromFile::ReadLineByLine(FScript Conversation,FString filepath,FString ConvoTitle)
{
	//Creation of Struct
	Conversation;
	//Array of Fstrings
	
	int limit=0;
	int skip=0;
	//changing filepath to a C string filepath i.e. Readable for VS
	std::string file(TCHAR_TO_UTF8(*filepath));
	std::string title(TCHAR_TO_UTF8(*ConvoTitle));
	int x=0;
	std::string line;
	bool found = false;
	Conversation.Dialouge.SetNum(0);
	Conversation.Color.SetNum(0);
	Conversation.Size.SetNum(0);
	//Scanner class
	ifstream in_file;
	in_file.open(file);
	if (in_file.is_open()) {
	
		//Not End Of File
		while(!in_file.eof()) {
			std::getline(in_file, line, '\n');
			skip++;
			if (line == title) {
				found = true;
				std::getline(in_file, line, '\n');
				limit = stoi(line);

				//declares size of everything
				Conversation.Dialouge.SetNum(limit);
				Conversation.Color.SetNum(limit);
				Conversation.Size.SetNum(limit);
			}
			if (line == ";") {
				found = false;
			}
			if (line == "Color" && found) {
				Conversation.Color=ColorPicker(limit,Conversation,file,skip);
				for (int i = 0;i < limit+1;i++) {
					std::getline(in_file, line, '\n');
					skip++;
				}
				
			}
			if (line == "Size" && found) {
				
				Conversation.Size=SizePicker(limit, Conversation, file,skip);
				for (int i = 0;i < limit+1;i++)
				{
					std::getline(in_file, line, '\n');
					skip++;
				}
				


			}
			if (found && !(line=="Color" || line=="Size" || line == title || line==to_string(limit) || line.empty()))
			{
				//String Back into Fstring
				cout << x << endl;
				Conversation.Dialouge[x] = line.c_str();
				x++;
				
			}
		}
		in_file.close();
		
		
	}
	
	return Conversation;
}

TArray<FString> UReadFromFile::ReturnDialouge(FScript script)
{
	return script.Dialouge;
}

TArray<FLinearColor> UReadFromFile::ReturnColor(FScript script)
{
	return script.Color;
}

TArray<int> UReadFromFile::ReturnSize(FScript script)
{
	return script.Size;
}


void UReadFromFile::WriteStringToFile(FString FilePath, FString String, bool& bOutSuccess, FString& OutInfoMessage)
{
	if (!FFileHelper::SaveStringToFile(String, *FilePath)) {
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Write String to File Fail, File is read only '%s'"));
		return;

	}
	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("It worked file read and written '%s"));
}


