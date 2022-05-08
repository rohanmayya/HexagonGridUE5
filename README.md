# HexagonGridUE5
Hexagon Grid Library written for Unreal Engine, in C++, extendable with Blueprints.

![Screenshot 2022-05-08 at 2 07 48 PM](https://user-images.githubusercontent.com/32911377/167288385-15403601-5da2-45c7-8c97-91320b40771c.png)


## Implementation Details

This is a simple Hexagon system to create hexes laid out in hexagon fashion. (More shapes to come soon!)
This is meant to exist for my own reference to best practices in Unreal Engine 5.

Specifically, a balanced workflow for C++ and Blueprints, to streamline my own experience while working with Unreal.

## Balancing C++ vs Blueprints

This project had 2 purposes: exploring hex based systems, and also figuring out a good workflow for using both C++ and Blueprints. I feel like my approach (which I'll discuss below) works well, especially for small teams, to build gameplay logic and for the artist to do their thing, without conflicts.

- The C++ bit takes care of all core gameplay logic, including the HexagonGrid, which is responsible for spawning the Hex Actors,
- I don't want to actually spawn the C++ actors, since I want my Hex actor to be configurable by the artist (materials, meshes, shaders etc), so I create a Blueprint of the Hex class,
- I declare a `	TSubclassOf<AHex> Hex;` in my HexGrid to hold a reference to *any* subclass of Hex (can use the original class as well)
- This allows me to assign any child of the Hex actor, so in my editor I create 2 Blueprints, 1 inheriting from Hex (BP_Hex) and 1 inheriting from HexGrid (BP_HexGrid),
- In BP_HexGrid, I assign Hex to my BP_Hex for use, so in runtime my game spawns my Hex blueprint.
- And voila! Now, I (or an artist) can make whatever changes required on the art side to the Hex blueprint, while the programmer works continues to work on the C++ side of things.

## Conclusion 

I've followed this [link](https://www.redblobgames.com/grids/hexagons/implementation.html) while working on this project. 
I'll probably add pathfinding, lengths between hexagons, vertex/edge calculations/caching sometime in the future.

This could easily serve as a starting point for your hexagon based game, if you're not willing to buy an asset off the marketplace.
If you like this project, do leave a star! Or if you have any suggestions/code ideas, do leave an issue/PR!
