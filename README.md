# SO_LONG

This project asks for the creation of a 2D game with the MLX graphics library. I have chosen a setting in Pokemon for this project.


<p align="center">
<img width="1346" alt="image" src="https://user-images.githubusercontent.com/113030191/231244614-4a4e99df-3d7d-444f-bc8e-e9c78275ab62.png">
</p>

<p align="center">
<img width="631" alt="image" src="https://user-images.githubusercontent.com/113030191/231206541-c44ff6a5-aa47-4a40-a5a4-2600cee1c4c7.png">
</p>
    
## MLX42 Library

Library implementation method and library functions used in this project:

### Installation

In my case, I only needed to do the following steps:

    curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

__________________________________________________________________________

    brew install glfw
    
If you need more information or have a problem, I leave here the link that I used: https://github.com/kube/42homebrew

### Functions used

**Mandatory :**

- **mlx_init**(**int32_t** width, **int32_t** height, **const char\*** title, **bool** resize) : Is a function in the **minilibx** library, which is a simple graphics library designed for use in C programming language. It function initializes the connection between your program and the graphics system.
- **mlx_load_png**(**const char\*** path) : Is a function in the **minilibx** library that allows you to load PNG images into your graphics program.
- **mlx_texture_to_image**(**mlx_t\*** mlx, **mlx_texture_t\*** texture) : Is a function in the **minilibx** library that converts a texture (an image that has been mapped onto a 3D object) to an **mlx_img** structure.
- **mlx_delete_texture**(**mlx_texture_t\*** texture) : Is a function in the **minilibx** library that frees the memory associated with a texture that was created **with mlx_new_texture()** function.
- **mlx_image_to_window**(**mlx_t\*** mlx, **mlx_image_t\*** img, **int32_t** x, **int32_t** y) : Is a function in the **minilibx** library that allows you to draw an image onto a window.
- **mlx_key_hook**(**mlx_t\*** mlx, **mlx_keyfunc** func, **void\*** param) : Is a function in the **minilibx** library that allows you to register a function to be called whenever a specific key is pressed or released on the keyboard. This function is often used to handle user input in interactive graphics applications.
- **mlx_close_window**(**mlx_t\*** mlx) : Is a function in the **minilibx** library that allows you to close a window that was created using **mlx_new_window()**. When you call this function, the specified window will be closed, and any resources associated with it will be freed.
- **mlx_loop**(**mlx_t\*** mlx) : Is a function in the **minilibx** library that enters an infinite loop to handle events from the windowing system, such as keyboard and mouse input.
- **mlx_terminate**(**mlx_t\*** mlx) : Is a function in the **minilibx** library that cleans up the resources allocated by **mlx_init()** and other functions in the library.

**Bonus :**

- **mlx_loop_hook**(**mlx_t\*** mlx, **void** (*f)(void*), **void\*** param) : Is a function in the **minilibx** library that allows you to register a function that will be called repeatedly while the event loop is running.
- **mlx_put_string**(**mlx_t\*** mlx, **const char\*** str, **int32_t** x, **int32_t** y) :  Is a function in the **MiniLibX (MLX)** library that displays a string on a window. 
- **game->mlx->delta_time** : The delta time is an important metric for calculating the rate of change in a game, as it allows the program to ensure that the game runs at a consistent speed on different hardware. I use this data to accumulate the execution time and make the enemy move in the case of reaching 0.5 seconds and make it move every 0.5 seconds.

<p align="center">
<img width="578" alt="image" src="https://user-images.githubusercontent.com/113030191/231243811-421ac877-d66a-4cc5-876d-1cdedcd1bc75.png">
</p>

## Usage

To compile the so_long program, run the following command **make**, and run **make bonus** for compile so_long_bonus.

To use the so_long program, run the following command:
        
        ./so_long map/*.bar

For so_long_bonus

        ./so_long_bonus map/bonus/*.bar

## Screenshot of Game

<p align="center">
<img width="894" alt="image" src="https://user-images.githubusercontent.com/113030191/231262410-163a8f29-81e7-4a1c-b60a-9ce3d0e2bbc3.png">

<img width="893" alt="image" src="https://user-images.githubusercontent.com/113030191/231262719-6af6ba41-7b3d-4893-9333-7ac5cb8e5521.png">

<img width="889" alt="image" src="https://user-images.githubusercontent.com/113030191/231263456-32e2f9e6-c725-4cae-ad3c-ed2a509e08ba.png">

</p>

### Links to my other projects at 42:

- **[Main Page](../../../Clocon)**
- **[libft](../../../libft-42)**
- **[ft_printf](../../../ft_printf-42)**
- **[get_next_line](../../../get_next_line-42)**
- **[pipex](../../../pipex-42)**
- **[push_swap](../../../push_swap-42)**




