# Chess Game
 
Authors: \<[Henri Malahieude](https://github.com/HenriMalahieude)\> \<[Tyler Chapman](https://github.com/Aywasa)\> \<[Zhuonan Long](https://github.com/NathanAOD)\> \<[Nhan Nguyen](https://github.com/ntnkan089)\>

## Project Description
* Chess is interesting because it will allow us to interact with both front end development and back end development.
   * Front end with GUI development
   * Back end with Algorithmic design of the game
   * Potentially creating a Chess AI for single player
* Planned languages/tools/technologies: (This list may change over the course of the project)
   * [C++](https://en.wikipedia.org/wiki/C%2B%2B) - The C++ coding language
   * [Raylib](https://www.raylib.com/) - The Raylib "Game Engine"
* Inputs/Outputs/Features
   * Inputs:
     * The mouse
   * Outputs:
     * The GUI interface
   * Features:
     * Graphical User Interface (GUI)
     * 1-2 Players


## Class Diagram
 > ![image](https://user-images.githubusercontent.com/102566544/166174564-6277fd94-59e6-4062-a8ad-7e5a16f18ca1.png)
 * **Description:**
   * Implement each piece using Pieces interface
   * Allow each player to Ask for Undo, Allow Undo, and Offer Draws
   * Board Class will include the pieces and the timer.
   * The start page can direct the player to the instructions page or start the game.
   
 * **Design Patterns:**
   
   *We are using the Strategy Design Pattern. It is most efficient for us to use it in this context, because the Strategy Abstract Class (in this case the Piece class) can be implemented by the context to easily house each different type of piece in the Chess game. Strategy allows us to easily implement polymorphism, and was almost implemented by accident before knowledge of the Strategy Design Pattern
   
 ## Class Diagram
 [Chess(5).pdf](https://github.com/cs100/final-project-cs100-dream-team/files/8801785/Chess.5.pdf)

 ## Installation/Usage
  ## Install (OLD):
* Download "Complete" folder
* Open folder, run Chess.exe  (for Windows only)
  ## How to Run:
* Open the Github Page
  ## Running: 
   * Just start playing
   * Interact with pieces by clicking on them
   * Click on a piece and click on a square to move the piece.
   * Timer available
   * Game ends when timer runs out/checkmate/stalemate
 ## Testing
 * At first, when the board and logic wasn't fully figured out, we put random pieces on the board and interacted with them
 * Towards the end, with the board fully laid out and pieces functional, we tested if the pieces were able to move correctly
 * We also added some win screens for all the results, this also helps with testing the timer, checkmates, and stalemate.
