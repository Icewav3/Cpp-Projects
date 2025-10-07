# Frogs and Toads

```
              _              _
  __   ___.--'_`.          .'_`--.___   __
 ( _`.'. -   'o` )        ( 'o`   - .`.'_ )
 _\.'_'      _.-'          `-._      `_`./_
( \`. )    //\`              '/\\    ( .'/ )
 \_`-'`---'\\__,            ,__//`---'`-'_/
  \`        `-\              /-'        '/
   `                                    ' 
```
[ascii art credit](https://www.ludd.ltu.se/~vk/pics/ascii/ascii3.shtml)

## Game Rules

The game is played on a linear board with N squares. In the variant we will be working with, N is equal to 7. All but the center square are filled with Frogs (F) to the left and Toads (T) to the right. The goal of the game is to get all the frogs and toads to switch places. 

The game is played by moving the frogs and toads, one at a time, into an empty square either by sliding into an adjacent square, or by hopping over a single occupied square into an empty one. Frogs can only move to the right. Toads can only move to the left.

Here’s an example of two initial moves in a game that begins in this state:  
`F	F	F	. T	T	T`

Move 1: The first toad slides into the empty square in the middle:  
`F	F	F	T	.	T	T`

Move 2: The first frog jumps over the first toad:  
`F	F	. T	F	T	T`

Play continues in this manner until all the toads are on the left and all frogs on the right. The player does *not* need to alternate between Frogs and Toads.

The winning state of the board looks like this:  
`T	T	T	. F	F	F`

If, before arriving at the winning state, no further moves are possible, the player loses.

An example of a losing state:  
`.	F	F	T	F	T	T`
