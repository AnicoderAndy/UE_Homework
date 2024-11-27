# UE_Homework
Homework for the Tencent public Game Dev class 2024. 腾讯2024游戏开发公开课客户端方向作业。

## Homework 2
Implement a minigame based on the Unreal FPS template. A round in the game lasts for `RoundTime` seconds. In a round, if a player shoots a cube, they get `BaseScore` and the cube scale to `ScaleMultiplier` times. Random `NumberBonusCubes` cubes in the level will give double points to the player. Different materials can be applied to bonus cubes.

### Configuration
Launch the .uproject file with Unreal Engine(5.4.4). You can configure the four variables mentioned above:

- Configure `BaseScore`(default: 10) and `ScaleMultiplier`(default: 0.5) in `BP_ChamferCube`
- Configure `RoundTime`(default: 10.0) and `NumberBonusCubes`(default: 4) in `BP_FirstPersonGameMode`
