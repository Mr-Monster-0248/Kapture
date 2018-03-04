# Kapture

## About the game

It is a board game that oppose two team handle by a playerit's composed with pawns that have different roles. The aim is to capture the ennemy flag. The board reprensent the map and there are differents types of field on it (rivers, forest).each team is on a side of the field and its pawn are grouped around the flag. The position of the flag is chosen at random. There is a fog of war o, the entire field that can be disovered by the player and it show the movements of visibles opponents.

## Our project

To realise the project we decided to make a graphic interface to make the project more argeale to play. To do so we used the librairy SDL 1.2. The program firstly load the map from a file "map.txt" then it choose the position of the flag and place the pawns.then it show the map and the game begin.

## Compilation
Being place in the main folder use the comand:
```gcc .\sources\*.c -o test.exe -lmingw32 -lSDLmain -lSDL```
