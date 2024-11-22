 # Stellar Strikers
 
 > Authors: \<[Kian Heydari Marvi](https://github.com/MERL10N)\>
 > \<[Rome Jone](https://github.com/rjone062)\>
 > \<[Steven Lau](https://github.com/stevenlau1343)\>
 > \<[Juan Zamora Cortes](https://github.com/JuanZ022)\>
 > \<[Leslie Velderrain](https://github.com/leslievelderrainx)\>

## Project Description
 > * Stellar Strikers is a 2D Space Shooter in which players are tasked to defend themselves from enemy ships for as long as they can. Enemies come in waves, which each subsequent wave becoming progressively more challenging. There will be a variety of enemies with their own set of attributes such as health, armor strength, and weapon type. The game ends when the player dies. 
 > * The purpose of this project not only serves as a fun way to put our C++ skills to the test, but also serves as an opportunity to dip our toes into Game Development in C++.

 > * Technologies used:
 >    * Language: C++
 >    * Library: Raylib (Graphics and Input) 

 > * Controls:
 >    * W - Move Up
 >    * S - Move Down
 >    * A - Move Left
 >    * D - Move Right
 >    * Space Key - Fire projectile
 >    * Escape Key - Pause Menu
 >    * Arrow Up/Down - Select menu button
 >    * Enter Key/Mouse click - Select menu button

 > * Proposed features:
 >   * Scoring System
 >   * Audio effects (Weapon fire, explosion, background music)
 >   * Powerups (Health recharge, damage boost, firerate boost)
 >   * Enemy AI (Using finite state machine)
 >   * Rounds-based progression
 >   * Sprite Animation (e.g for explosions) 

 > ## Phase II
 
## User Interface Specification

### Navigation Diagram
> ![Navdiagram](https://github.com/user-attachments/assets/025e93f5-ba2f-415f-a4a7-94e3bb872dd0)


### Screen Layouts
<img width="512" alt="image" src="https://github.com/user-attachments/assets/e9005732-0534-41f9-b277-b469392c74d5">
<img width="512" alt="image" src="https://github.com/user-attachments/assets/17a5fd80-d160-4da7-8273-e46ce0e69811">
<img width="512" alt="image" src="https://github.com/user-attachments/assets/250e2607-0016-400e-b1d3-e60551d8d791">

## Class Diagram

<img width="430" alt="image" src="https://github.com/user-attachments/assets/71727089-ea46-4556-89d3-dc9c85d651dd">


- Main Menu is where the program will start and it will generate the gameManager as well as provide a way to exit the game window or start the game
- GameManager will contain all components of the actual gameplay classes such as all subsequent menus + navigations and gameplay elements such as players and enemies
- scoreboard is a part of the GameManager and displays scores for the round as well as cumulative score
- PauseMenu is a part of the gameManager and will pause the game and provide options to resume, restart, and quit the game
- GameOver is a part of gameManager and displays after the player loses. It will get the user's name and add it to the leaderboard that will display on screen. There are options to quit to mainMenu or to restart the Game.
- Player is the user and is a part of the gameManager. Player will give details on the position and status of the user
- Enemy is a part of the gameManager. Enemy will contain details on the position and status of an individual enemy
-weapon is an aggregate of player and enemy and contains details on the statistics and operations of the attack
-PowerUp is a dependency of Player and contains details on various powerups that can be applied to the player. It keeps track of the position of powerUps as well
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * Make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
>  * Each team member should also submit the Individual Contributions Form on Canvas for phase III. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for phase III, and a description of their contributions. Remember that each team member should submit the form individually.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history.
>  * Each team member should also submit the Individual Contributions Form on Canvas for this final phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for the final phase, and a description of their contributions. Remember that each team member should submit the form individually.
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
