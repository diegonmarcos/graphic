# GRAPHICS ALGOS, FRAMEWORKS AND APIs
## Rendering Algorithms
### Ray Tracing
- Simulates light rays as they interact with objects
- Creates highly realistic images with accurate shadows, reflections, and refractions
- Computationally expensive but produces photorealistic results
- Used in offline rendering and increasingly in real-time with hardware acceleration

### Rasterization
- Converts 3D geometry into 2D pixels (fragments)
- Much faster than ray tracing but less physically accurate
- The primary method for real-time rendering in games and interactive applications
- Requires techniques like shadow mapping and screen space reflections to simulate effects

<details>
Subtypes and techniques within the Rasterization rendering category:

### Rasterization Subtypes and Techniques

#### Polygon/Triangle Rasterization
- Converts polygons (usually triangles) into pixels
- The foundation of most real-time 3D graphics
- Uses scan-line or half-space algorithms to determine which pixels a polygon covers

#### Texture Mapping
- Applies 2D images onto 3D geometry
- Includes various filtering methods (bilinear, trilinear, anisotropic)
- UV mapping determines how textures wrap around objects

#### Z-Buffer (Depth Buffer) Rendering
- Uses a depth buffer to determine which objects are visible at each pixel
- Solves the hidden surface problem efficiently
- Standard in almost all real-time graphics pipelines

#### Deferred Rendering
- Splits rendering into multiple passes (geometry, lighting, composition)
- Allows for many light sources with better performance
- Stores intermediate results in G-buffers (geometry buffers)

#### Forward Rendering
- Traditional approach where lighting is computed during polygon rendering
- More direct but less efficient for many light sources
- Still used for transparent objects and some specific cases

#### Tile-Based Rendering
- Divides screen into tiles and processes them separately
- Improves cache coherence and memory bandwidth usage
- Common in mobile GPUs and some console architectures

#### Order-Independent Transparency
- Techniques to correctly render transparent objects without pre-sorting
- Examples include depth peeling and weighted-blended OIT
- Addresses a challenging problem in rasterization pipelines

#### Screen Space Effects
- Techniques that operate on the already rasterized image
- Includes SSAO (Screen Space Ambient Occlusion), SSR (Screen Space Reflections)
- Approximates complex lighting effects without ray tracing

#### Voxel-Based Rendering
- Uses 3D grid cells (voxels) instead of polygons
- Can be rasterized using specialized algorithms
- Used for volumetric data and some specialized rendering engines

#### Point-Based Rendering
- Represents surfaces with points instead of polygons
- Includes techniques like splatting to create continuous surfaces
- Useful for very complex geometry like particle systems

#### Cel/Toon Shading
- Non-photorealistic rendering technique with discrete shading bands
- Creates cartoon-like or illustrated appearance
- Uses edge detection and color quantization

Each of these techniques can be combined in various ways within a rasterization pipeline to achieve different visual results and performance characteristics depending on the application's requirements.
</details>

### Path Tracing
- An unbiased rendering technique that extends ray tracing
- Simulates light paths more completely for greater realism
- Used extensively in film production and architectural visualization
- Slow for real-time applications but produces very high quality results

### Radiosity
- Calculates diffuse light transfer between surfaces
- Good for architectural visualization and environments with indirect lighting
- Often combined with ray tracing for complete global illumination

## Graphics Frameworks and APIs
### Low-level APIs
- DirectX (Windows platforms)
- Vulkan (cross-platform)
- Metal (Apple platforms)
- OpenGL (cross-platform, older)
- WebGL (browser-based)

### Game Engines
- Unreal Engine
- Unity
- Godot
- CryEngine

### Production Rendering Systems
- Arnold
- RenderMan
- V-Ray
- Redshift
- Octane Render

### Scientific Visualization
- OpenGL Visualization Toolkit
- ParaView
- POV-Ray

<br><br><br><br><br><br>

# THE CHOSEN METHOD
## Rasterization Category
### Vector-Based Wireframe Algorithm
- Represents 3D objects using only their edges (vectors/lines)
- Focuses on geometric structure rather than solid surfaces
- Efficiently displays objects with minimal computational resources
- Often used as a visualization mode in CAD software, modeling applications, and during the development process

Vector-based wireframe rendering is characterized by:

1. **Geometric Representation**: Objects are defined by their vertices and the connecting edges, ignoring faces and solid volumes
   
2. **Line Drawing Algorithms**: Uses algorithms like Bresenham's line algorithm or DDA (Digital Differential Analyzer) to efficiently draw straight lines between vertices

3. **Culling and Clipping**: Determines which lines are visible and which fall outside the viewport

4. **Projection**: Applies perspective or orthographic projection to convert 3D coordinates to 2D screen space

5. **Hidden Line Removal**: More advanced wireframe renderers may implement algorithms to hide edges that would be occluded by faces in a solid model

Wireframe rendering is particularly important in:
- Computer-Aided Design (CAD) software
- 3D modeling applications
- Engineering visualization
- Early stages of game and application development
- Limited computing environments where full rendering is too resource-intensive

It's worth noting that wireframe rendering represents an earlier, more fundamental approach to computer graphics that predates more sophisticated techniques like filled polygon rendering, texture mapping, and lighting models. However, it remains useful as both a visualization option and as an initial step in more complex rendering pipelines.

<br><br><br><br><br><br>

# THE PROJECT
## (i) Code Organization for a Graphic Project

This fdf project demonstrates an example of structured code organization for a graphics project. Here's the breakdown of how it's organized:

1. **Modular Architecture**:
   - Files are organized with a clear numbering system (1___, 3___, etc.) that indicates module relationships
   - Each file has a specific role in the rendering pipeline
   - Functions are grouped by their purpose (loading, drawing, parsing)

2. **Data Structures**:
   - The project uses a central `t_meta` structure that contains all necessary information
   - `t_map` structure to store the map data
   - `t_point` structure to store individual points with their coordinates and color

3. **Processing Pipeline**:
   - **Map Loading**: Files starting with `1___` handle reading the input file and parsing it
   - **Map Parsing**: Files starting with `3_2__` handle transformations of the points
   - **Map Drawing**: Files starting with `3_3__` handle the actual rendering

4. **Separation of Concerns**:
   - Initialization logic is separated (`system_init`, `map_ini`)
   - Transformation logic is separated (matrix operations in separate files)
   - Rendering logic is separated (background, lines, points)
   - Memory management is handled consistently

This organization follows good software engineering principles, making the code maintainable and extensible. The pipeline structure (load → transform → render) is particularly suitable for graphics projects as it follows the natural flow of data processing.

## (ii) Manipulating MiniLibX

The project shows several ways of interacting with the miniLibX library:

1. **Window and Image Management**:
   - Creating a window with `mlx_new_window` (implied in `system_init`)
   - Creating an image buffer with `mlx_new_image` (implied in `system_init`)
   - Pushing the image to the window with `mlx_put_image_to_window`
   
2. **Pixel Manipulation**:
   - Direct memory access to the image buffer (`meta->bitmap.buffer`)
   - Color handling with `mlx_get_color_value` for different bit depths
   - Setting pixel colors with the `set_color` function
   
3. **Event Handling**:
   - Setting up key hooks via `system_init_keys`
   - Likely uses `mlx_hook` and `mlx_key_hook` to capture user input
   
4. **Performance Optimization**:
   - Using an in-memory buffer to render the entire scene before displaying it
   - Measuring rendering performance with `clock()`
   - Double-buffering technique (preparing the image before showing it)

The project uses a clever approach of rendering to an off-screen buffer first, then displaying the completed image, which reduces flickering and improves performance - a common technique in graphics programming.

## (iii) Math Concepts in Vector-Based Wireframe Algorithm

This is where the project really shines, implementing several key mathematical concepts:

1. **Matrix Transformations**:
   - 3D rotation matrices for X, Y, and Z axes (`rotate_x`, `rotate_y`, `rotate_z` in `3_2_2_parse_matrix.c`)
   - Matrix multiplication for applying transformations (`matrix3_multp`)
   - Orthographic projection to convert 3D to 2D (`ortogonal_projection`)

2. **Coordinate Systems**:
   - Cartesian coordinates (X, Y, Z axes)
   - Spherical/polar coordinates (`go_polar` function, using latitude and longitude)
   - Conversion between coordinate systems

3. **Scan Conversion Algorithm**:
   - The project have both uses Bresenham's line algorithm or Digital Differential Analyzer (DDA) for line drawing
   - This was implemented in the `wired` function (referenced in `drawing`)

4. **Additional Mathematical Operations**:
   - Scaling of points to fit the display (`scale` function)
   - Translation of points to position them correctly (`traslate` function)
   - Z-divisor to control the height effect (`z_division` function)
   - Bending for curvature effects (`bending` function)
   - Color gradients based on height (`gradient` function)

5. **Spherical Projection**:
   - Conversion from Cartesian to spherical coordinates in `go_polar`
   - Allows for globe-like rendering with `spherize` function

The scan method in this project's wireframe algorithm appears to be implemented through the combination of the orthogonal projection and then drawing lines between adjacent points in the transformed coordinate space. The mathematical pipeline goes:

1. Load points from file (original Cartesian coordinates)
2. Apply z-scaling and other adjustments
3. Apply rotations through matrix multiplication
4. Project to 2D using orthographic projection
5. Scale and translate to position in the window
6. Connect points with lines to form the wireframe

The project combine the concepts of: 
	- linear algebra, 
	- coordinate geometry, and 
	- computer graphics principles, 
	- combined into a cohesive rendering pipeline.

This type of wireframe rendering is foundational to more complex graphics algorithms and provides an excellent learning platform for understanding how 3D rendering works at a mathematical level.