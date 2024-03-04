# English

## Geometry Hater

### Description:
Geometry Hater is a fast-paced action game set in a geometric world filled with enemies. The game falls under the genre of arcade shooter.

### Main Game Flow:
- **Start**: The game begins with the main menu screen where players can start the game.

![Main menu screen](screenshots/menu.png)

- **Game Process**: Players control a character navigating through a geometric field, encountering various enemy shapes. The player can move using keyboard controls and shoot enemies using the mouse. The goal is to survive as long as possible while defeating enemies and avoiding their attacks.
- **End Conditions**: The game ends when the player's character runs out of health points (HP) due to enemy attacks. Upon death, players can restart the game.
- **Game Interruptions**: Players can pause the game by pressing the 'P' key, which brings up a pause menu. The game can also be exited by pressing the 'Escape' key or closing the game window.

### Available Game Mechanics:
1. **Player Movement**: Players can move their character using the arrow keys or WASD keys.

![Player](screenshots/player.png)

2. **Shooting Mechanic**: Players can shoot bullets towards enemies by aiming with the mouse cursor.
3. **Enemy Interaction**: Enemies spawn randomly on the map and move towards the player. Players must dodge enemy attacks while shooting them down.

![Triangle enemy](screenshots/triangle.png)
![Circle enemy](screenshots/circle.png)

5. **Health and Experience System**: The player has a health bar (HP) that decreases upon taking damage from enemies. Players gain experience (Exp) by defeating enemies and can level up with enough experience points. Upon reaching a new level, the player's attack speed increases.
6. **UI Elements**: The game features UI elements such as health and experience bars, displayed on the screen to provide player feedback.

![Health and experience bars](screenshots/bars1.png)
![Health and experience bars](screenshots/bars2.png)

7. **Game Audio**: The game includes background music and sound effects for player actions.

### Implemented Technical Systems:
1. **High-Level Game Modules**: The game is structured using classes like `Game`, `Player`, `Enemy` and so on, and different enemy subclasses (`CircleEnemy`, `TriangleEnemy`).
2. **NPC Algorithms**: Enemies utilize simple movement and attack algorithms to approach and engage the player character.
3. **Camera Work**: The game implements a camera system that centers on the player character, ensuring they remain in view while navigating the game world.
4. **Procedurally Generated World**: The background grid is rendered in its entirety at once, providing a visually appealing environment for gameplay. This approach allows for a diverse range of textures and patterns without the need to store a large number of resources.
5. **Player Control**: Keyboard and mouse input are utilized for player control, enabling movement and shooting mechanics.
6. **Save Mechanisms**: The game does not appear to include save mechanisms, likely relying on a single-session gameplay experience.
7. **UI Features**: The UI elements, including health and experience bars, are dynamically updated to reflect the player's status during gameplay.

### Future Improvements:
- **Boss Enemies**: Introduce boss enemies with unique attack patterns and increased difficulty levels.
- **Upgrade System**: Implement a system where players can choose upgrades or abilities upon leveling up, enhancing their character's capabilities.
- **Leaderboard**: Add a leaderboard system to track players' best times or scores, providing a competitive element to the game.
- **New Sound Effects**: Include additional sound effects for various in-game actions, such as player movements, enemy attacks, and environmental interactions.
---
