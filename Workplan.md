# Workplan

The program has to go through the following steps during execution:

- parsing
	- create main structure that contains or points at all the information in the input (`t_ctx`)
	- use vectors to represent points in space and directions
	- use linked lists (from Libft) for elements that can be declared more than once (e.g. `sp`, `pl` and `cy`)

- compute the orientation of each ray associated with a pixel on the result image
	- each ray is determined only by an orientation, as the starting poing of the ray is the point where the camera sits at.
	- ...

- compute the rays' path and resulting color for the corressponding pixel (ray tracing)
	- find all points of intersection between the ray and any object
	- find the first point of intersection 
	- identify the lightning in that point
		- find the ray from the light to that point
		- proof whether this ray meets other objects before
	- compute the resulting color at that point

- display the image
	- set up a MiniLibX image
	- fill the image with information from ray tracing
- exit
	- set up MiniLibX hooks to quit the program
	- free the structures created during parsing and to display the image


## Objects we need in our programm

| What | Properties | Questions? |
| - | - | - |
| Vectors | All vectors in the program are three-dimensional | | 
| | They can represent either **points in space** or **directions** | One type for both or two types with same structure?  |
| | Each of the three components of the vector is a `float`.
| Colors | Defined by three integer numbers in the range 0-255 (RGB) | struct with `char` or `int` ? |
| Spheres | Defined by a center (vector / point in space), a diameter (float), a color | The input file contains the diameter, but it would be more useful to save directly the radius. Could this be done during parsing? |
| Planes | Defined by any point on the plane (vector / point in space) and an orientation, given by the normal vector that is perpendicular to any line on the plane (vector / direction) a diameter (float), and a color | |
| Cylinders | Defined by a center (vector / point in space), an orientation (vector / direction),  a diameter (float), a height (float) and a color | Diameter vs. radius as in the case of a sphere? |
| Lists | A list for spheres, planes or cylinders are needed to represent the scene. ||

## Functions

Function of special importance for the programm to work coherently:

- A function that given two points in space computes the direction of a ray going from the first to the second.

- A function that given a direction and the context does the ray tracing and returns the color. 

```C
int direction(t_coord first_point, t_coord second_point, t_direction *result);
int	tracing(t_ctx *ctx, t_direction direction, t_color *result);
```



# Ressources