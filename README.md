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
 
 ## Screenshots

* Sample game:
 > ![image](https://user-images.githubusercontent.com/102566544/170843402-e598d853-775a-4475-a587-3edd27527f04.png)
 > ![image](https://user-images.githubusercontent.com/102566544/170843420-ba709e48-ddb2-4523-b9e7-867f9334c3e0.png)
 > ![image](https://user-images.githubusercontent.com/102566544/170843439-5468c35c-b6bc-4015-a4f5-b494bd13f425.png)

* Timer:
 > ![image](https://user-images.githubusercontent.com/102566544/171079679-b6dccd4f-9e0f-43eb-a29d-e2ab100faad2.png)
 > ![image](https://user-images.githubusercontent.com/102566544/171080014-179f8690-bf1a-47c3-99a7-559aa9b2f68f.png)
 > ![image](https://user-images.githubusercontent.com/102566544/171080551-d1b7f84d-4c5a-48c0-bea7-d84114b04651.png)
 > ![image](https://user-images.githubusercontent.com/102566544/171081191-5f45a35f-f5b8-406d-bb0d-dacb0db030bc.png)
 > ![image](https://user-images.githubusercontent.com/102566544/171082007-7905a350-157f-4799-9f1f-f0ead940e135.png)

 
* Castling:
 > ![image](https://user-images.githubusercontent.com/102566544/170843448-cd3ccbe0-2776-4f15-bbc9-3b8186d8a2ce.png)
 > ![image](https://user-images.githubusercontent.com/102566544/170843501-b03c6ee8-479a-423b-93ed-d77cccb508ab.png)
 > ![image](https://user-images.githubusercontent.com/102566544/171080839-1ca01f3e-f9f9-44a0-9eed-536c248bdbc7.png)
 > ![image](https://user-images.githubusercontent.com/102566544/171081640-def8624a-b943-4d1e-a953-dfeda3804b28.png)
 > ![image](https://user-images.githubusercontent.com/102566544/171082087-018fc022-0b51-458f-85ed-9f0e4307ab2f.png)
 
 
* Checkmate:
 > ![image](https://user-images.githubusercontent.com/102566544/171076205-bb1ffee8-56db-49f8-a531-607101ef64e8.png)
 > ![image](https://user-images.githubusercontent.com/102566544/171076403-d3632a5f-697a-4eee-88eb-e310d0d94b6c.png)
 > ![image](https://user-images.githubusercontent.com/102566544/171076581-ea263d7c-27f5-4cd7-a940-327356fa6b38.png)
 > ![image](https://user-images.githubusercontent.com/102566544/171082279-26e0be7e-c8db-4acd-a791-7130a54d2c48.png)
 > ![image](https://user-images.githubusercontent.com/102566544/171082498-41b0aefa-604d-4228-925d-7e1a572cac0f.png)


* Stalemate:
 > ![image](https://user-images.githubusercontent.com/102566544/171076893-18d69989-4fa8-43d6-adae-9932d1b33102.png)
 > ![image](https://user-images.githubusercontent.com/102566544/171083572-26593cf5-18d3-4677-a3f8-5a61f483c213.png)
 > ![image](https://user-images.githubusercontent.com/102566544/171086358-d37a3a6d-a051-4902-90e7-73daba0c8e67.png)



* Promotion:
 > ![image](https://user-images.githubusercontent.com/102566544/171083247-764751e6-20c5-4ba3-a0ce-67d050e7680b.png)
 > ![image](https://user-images.githubusercontent.com/102566544/171084507-953a7be2-ed1a-48ea-93b8-4486d23c5403.png)
 > ![image](https://user-images.githubusercontent.com/102566544/171086093-2c42cf86-77b7-4031-9e58-69ecaa2a0573.png)

 ## Class Diagram
 [Chess(5).pdf](https://github.com/cs100/final-project-cs100-dream-team/files/8801785/Chess.5.pdf)

 ## Installation/Usage
  ## Install:
* Download "Complete" folder
* Open folder, run Chess.exe  (for Windows only)
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