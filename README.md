# SO_LONG

This project asks for the creation of a 2D game with the MLX graphics library. I have chosen a setting in Pokemon for this project.

<img width="631" alt="image" src="https://user-images.githubusercontent.com/113030191/231206541-c44ff6a5-aa47-4a40-a5a4-2600cee1c4c7.png">

## MLX42 Library

Library implementation method and library functions used in this project:

### Installation

In my case, I only needed to do the following steps:

    curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh


    brew install glfw
    
If you need more information or have a problem, I leave here the link that I used: https://github.com/kube/42homebrew

### Functions used

Mandatory :

- **mlx_init**(**int32_t** width, **int32_t** height, **const char\*** title, **bool** resize) : Is a function in the **minilibx** library, which is a simple graphics library designed for use in C programming language. It function initializes the connection between your program and the graphics system.
- **mlx_load_png**(**const char\*** path) : Is a function in the **minilibx** library that allows you to load PNG images into your graphics program.
- **mlx_texture_to_image**(**mlx_t\*** mlx, **mlx_texture_t\*** texture) : Is a function in the **minilibx** library that converts a texture (an image that has been mapped onto a 3D object) to an **mlx_img** structure.
- **mlx_delete_texture**(**mlx_texture_t\*** texture) : Is a function in the **minilibx** library that frees the memory associated with a texture that was created **with mlx_new_texture()** function.
- **mlx_image_to_window**(**mlx_t\*** mlx, **mlx_image_t\*** img, **int32_t** x, **int32_t** y) : Is a function in the **minilibx** library that allows you to draw an image onto a window.
- **mlx_key_hook**(**mlx_t\*** mlx, **mlx_keyfunc** func, **void\*** param) : Is a function in the **minilibx** library that allows you to register a function to be called whenever a specific key is pressed or released on the keyboard. This function is often used to handle user input in interactive graphics applications.
- **mlx_close_window**(**mlx_t\*** mlx) : Is a function in the **minilibx** library that allows you to close a window that was created using **mlx_new_window()**. When you call this function, the specified window will be closed, and any resources associated with it will be freed.

