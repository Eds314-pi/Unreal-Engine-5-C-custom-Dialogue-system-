## Configuring TXT
To acheive this dialogue system the developer modifies a txt which is then passed into the blueprint node the following format is designed to help with this.
Each conversation must have a title and is how the dialogue is found, speed is set in the node itself

```text
Intro
2
Hello there!
Pleased to meet you
Color
255,255,255
0,0,0
Size
24
30
;
Boss intro
2
Prepare yourself collared one
Only one walks...
Color
0,0,0
255,50,50
Size
28
32
;
```
Note: To allow full customization the user must include a color for each line as well as size. Line counts need to be given and begin at 1. Conversations end with a semi colon
