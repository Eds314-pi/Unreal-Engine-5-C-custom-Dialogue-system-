#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ReadFromFile.generated.h"

using namespace std;
/**
 * 
 */
USTRUCT(BlueprintType)
struct READINGFILE_API FScript
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Dialouge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FLinearColor> Color;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Size;
};

UCLASS()
class READINGFILE_API UReadFromFile : public UObject
{
	
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "Everett Sherman - ReadFile")
	static FString ReadStringFromFile(FString FilePath, bool& bOutSuccess, FString& OutInfoMessage);

	UFUNCTION(BlueprintCallable, Category = "Everett Sherman - ReadFile")
	static FScript ReadLineByLine(FScript Conversation,FString filepath, FString ConvoTitle);

	UFUNCTION(BlueprintCallable, Category = "Everett Sherman - ReadFile")
	static void WriteStringToFile(FString FilePath, FString String, bool& bOutSuccess, FString& OutInfoMessage);

	UFUNCTION(BlueprintCallable, Category = "Everett Sherman - ReadFile")
	static TArray<FString> ReturnDialouge (FScript script);

	UFUNCTION(BlueprintCallable, Category = "Everett Sherman - ReadFile")
	static TArray<FLinearColor> ReturnColor(FScript script);

	UFUNCTION(BlueprintCallable, Category = "Everett Sherman - ReadFile")
	static TArray<int> ReturnSize(FScript script);
	
	
};



