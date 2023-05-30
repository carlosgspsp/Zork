# ZORK
Zork is a short and simple conversational game based on [Zork Game](http://textadventures.co.uk/games/view/5zyoqrsugeopel3ffhz_vq/zork) created by Tim Anderson, Marc Blank, Bruce Daniels, and Dave Lebling.
- [Zork Github Repository](https://github.com/carlosgspsp/Zork)

## Installation

Download zip file in [release](https://github.com/carlosgspsp/Zork/releases), unzip it and execute the Zork.exe file.

## Commands Guide

List of commands
- The 'LOOK' command prints a description of your surroundings.
- The 'GO direction' command moves the player to the room in the choosen direction.
- The 'INVENTORY' command show the player´s inventory.
- The TAKE item' command take the item from the scenario and puts it in the player inventory.
- The 'DROP item' command puts and item from the player´s inventory on the scenario.
- The 'PUT item IN container' command put and item from the player´s inventory or the scenario into another object´s inventory.
- The 'QUIT' command quits the game. 

Commands Abbreviations
- 'LOOK' command may be abbreviated 'L'
- 'INVENTORY' command may be abbreviated 'I'
- 'QUIT' command may be abbreviated 'Q'
- 'GO' - command may be abbreviated by using only the direction or the first letter of the direction.
Example: "Go north" can be written as "north" or as "n".

Avaiable Directions
- NORTH
- SOUTH
- WEST
- EAST
- UP
- DOWN

## Game Completition Guide
The objetive of the game is to find the treasure hiding in the house and take it.

The player starts west of the house. There is a mailbox with an stone key. The player have to take it with the command "take stone key".

Then go north and go east to be behind the white house. There the player will see a backdoor that leads to a kitchen. If the player has the stone key in its inventory, when entered the command "go west" the door will open and the player will go inside the kintchen.

From the kitchen there are two destinations possible. The attic (which requires a key to be opened) and the living room. On the kitchen table is a wooden key, the player should take it with "take wooden key" command.

After that the player should go west to the living room ("go west" command) and then down to the basement("go down" command). Thanks to the wooden key taken in the kitchen, now the basement door is open and the player is inside it.

In the basement there is a steel chest with an iron key inside it, the player should take it to access the attic ("take iron key" command). After that, the player should go back to the kitchen ("go up" and "go east" commands) and go upstairs to the attic ("go up" command).

In the attic there is a golden chest with a treasure inside. If the players takes the treasure ("take treasure" command) the player will win and the game will be finished.

## Author
- [Carlos García Segura](https://github.com/carlosgspsp)
## License

MIT License

Copyright (c) [2023] [Carlos García Segura]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.