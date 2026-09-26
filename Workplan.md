# Workplan

- parsing
	- create main structure that contains or points at all the information in the input
	- use vectors to represent points in space and directions
	- use linked lists (form Libft) for elements that can be declared more than once (e.g. `sp`, `pl` and `cy`)

- compute the orientation of each ray associated with a pixel on the result image
	- each ray is determined only by an orientation, as the starting poing of the ray is the point where the camera sits at.

- compute the rays' path and resulting color for the corressponding pixel (ray tracing)
	- find the first point of intersection between the ray and any object
	- identify the lightning in that point
		- find the ray from the light to that point
		- proof whether this ray meets other objects before
	- compute the resulting color at that point

- display the image
	- set up a Minilibx image
	- fill the image with information from ray tracing
- exit
	- set up Minilibx hooks to quit the program
	- free the structures created during parsing and to display the image


## Objects we need in our programm

| What | Properties | Questions? |
| - | - | - |
| Vectors | All vectors in the program are three-dimensional | | 
| | They can represent either **points in space** or **directions** | One type for both or two?  |
| | Each of the three components of the vector is a `float`.
| Colors | Defined by three integer numbers in the range 0-255 | struct with `char` or `int` ? |

## Functions

- A function that given two points in space computes the direction of a ray going from the first to the second.



# Ressources