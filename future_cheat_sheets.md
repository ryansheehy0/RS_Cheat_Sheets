# Prioritized future cheat sheets

- STM32 discovery kit
	- Uses arm Cortex-M
	- Program in C
	- STM32 cubed
- XMC48
- Ti microcontrollers
- C/C++
- Digital signals processing
	- Finite impulse response
	- Infinite impulse response
- Serial communications
	- Ethercat
	- I2C
	- UART
- Real time OS
	- FreeRTOS
	- RTX5
	- ThreadX



- A*
    - Also include a variable length
- PIDs
    - Predict where the robot will be in the future. The D(the rate of change) limits the velocity.
- Make files
- GDB - GNU Debugger
- C++ Data Structures, Iterators, and Algorithms
- C++ Standard Libraries
- C++ Non Standard Libraries
- Newtons Method
- Simultaneous localization and mapping
- C++ template meta programming
- Convolutions
    - Gaussian blur
    - Canny edge detections
    - Some algo to extract useable info
        - How to get the location of the camera given a new image of a retro-reflective object and a previously known position with a corresponding image?
- Quantum computers
- AWK programming langue
- Designing data intensive applications book

# Future Cheat Sheets
- Optimizations in cpp
- Neural Nets
- Evolutionary algorithm
- Hopfield Network
- Trees
    - Binary Heaps
- Sliding window
- Depth first search and breadth first search
- Hash tables
- Awk
- React
- Redo Newtons method
- Redo Taylor Series
- Fourier transform
    - https://www.youtube.com/watch?v=cDr_y0kGddA
- SAT solvers
- Quantum computers
- Machine learning
	- There are certain problems that are so difficult that you can't create an algorithm to solve them, you can only create an algorithm that can create an algorithm to solve the problem.
	- How do you know if a problem is too complex that you cannot create a relatively simple algorithm to solve it? Are these NP problems?
- Orthogonal arrays
- Phase space
- Statistics
- Linear algebra
- Operating systems
- Advanced algorithms

## Map of machine learning
- Gradient decent
- Unsupervised learning, supervised learning, reinforcement learning

- Regression
- Clustering
- Classification
- Dimensionality Reduction

- Kernel
- LLM
    - There's some randomness

- Evolutionary algorithm
- Monte Carlo algorithm
- Gradient descent
    - Incremental changes get you closer and closer to the solution
    - The hill might not be tall enough to solve the problem
    - Randomness might take you away from the local maxima
        - What if you increasingly add more and more randomness, until you jump to a new local maxima?
            - The only solution is to guess and check. Like solving a hash.

- Phase spaces/Multi-dimensions
    - Configuration space
    - Can't look at the whole space at once
    - SAT Solvers
        - Boolean satisfyability
        - Z3
        - How to translate
        - Edents

- NP vs P
    - Non-polynomial time
        - Does this relate to the taylor series
    - NP = exponential O of time
    - NP complete = can be reasonably solved for low N values

- You're given a large sequence of data. Data correlated with a score. Use AI to make a patter between the input data and the score. And have that AI tell you which parts of the data are needed to produce a good score.
    - How could you get the knowledge from the AI?
- Object classification
    - And gaining other info about the object
- LLM
- Can everything be represented by object classification? Is intelligence just object classification?
    - How could you apply the idea of object classification to LLMs?

- What's the fundamental problem ML is trying to solve.

- New subject do clarification.
- ML is used to solve NP problems.
- There are a whole lot of ways to solve NP problems. What is the best way to solve them?
    - ML
    - SAT solvers
    - What are the things your're trying to optimize?
        - Translating the problem into another form which can be solved by a computer.
            - CPU or GPU?

## Other ideas

- Communication Algorithms
    - Encryption
        - RSA
        - Blum Blum Shub
        - Rabin Hash Function
        - Linear Shift register
        - Linear Congrential Generator(LCG)
        - Block chains
        - Shor codes(quantum)
        - Key exchanges
            - 2 lock key exchange
            - delphi helmen key exchange
        - Elliptic curve
        - Lattice Points encryption
            - [How Quantum Computers Break The Internet... Starting Now](https://www.youtube.com/watch?v=-UrdExQW0cs)
    - Error correction
        - Turbo codes
        - Read-Solomon Codes
        - ISBNs
        - Hamming codes
			- [Part 1](https://www.youtube.com/watch?v=X8jsijhllIA)
			- [Part 2](https://www.youtube.com/watch?v=b3NxrZOu_CE)
        - CRCs
    - Compression
		- Lossy
			- [JPEG](https://www.youtube.com/watch?v=0me3guauqOU)
		- Lossless
			- [PNG](https://www.youtube.com/watch?v=EFUYNoFRHQI)
			- [Huffman codes](https://www.youtube.com/watch?v=B3y0RsVCyrw)
    - Serial Communications
        - Light(AM and FM)
        - Ti Calculators
        - USB Serial Protocol
        - UART
        - I2C
        - Can Bus
- Math/Statistics
    - Cross Product/Dot product
    - Wavelets
    - Binomial distribution
    - Hyperbolic trig
    - Complex/imaginary numbers
    - Pareto Distribution
    - Multi-variable calculus
    - Differential Equations
    - Extended factorial function
    - Matrixes
    - Integrals with circles
    - Bell Curves
- AI
    - Machine learning
    - Kernel machines
    - Unsupervised learning
    - Adaptive Learning Rates and Momentum(Adam)
    - Transformers
    - Convolutional neural network
- Physics
    - Newtonian, Lagrangian, Hamiltonian physics
    - Maxwell's equations
    - Light/Electro magnetic waves
    - 6 simple machines
    - Stress/strain
    - Einstein's special relativity
    - Aerodynamics
    - HVACs/Heat Pumps
    - Transistors. Mosfets, BJT including darlington, and JFETs
    - Hydraulics
    - Triangulation and GPSs
- Computer Science
    - Arm assembly
    - x86 assembly
    - CPU architecture
    - Quantum computing
    - Internet
    - Domain Name System(DNS)
    - http and https
    - Breadth first search vs depth first
    - Comparing 2 binary trees
    - Grep and other linux tools
    - Different search algorithms
    - Magnitude of complexity for common programming things. Like for loop, while loop, 2 for loops etc.
    - Common linux terminals
    - Multi-threading
- Chemistry
    - Plastics
    - Electrolysis
    - Explosives
    - Poisons
    - Bleach
- Important Algorithms
    - Fast Fourier Transform
    - PIDs and motion profiling
- Mechanical
    - Unpickable lock
    - Delays for small arms

SystemD
    - sudo dpkg-reconfigure resolveconf
Github
Stripe payment processing
React
Mongoose
Null Window Manager
MUI
Prevent race conditions for db changes like Google Docs
React Native
Docker/Kubernetes
Breadth first vs depth first
Nginx
tRPC
Accessibility standards
Database scaling
express-ws
Orthogonal(Taguchi arrays)
Google authentication
FIDO authentication
Publish PWA on google play store
B-trees
Sorting algorithms
Machine learning
Neural networks
Gradient Descent

Algorithms
- Memory managed hash table
    - Arrays are slow to retrieve data(high computations), but take up only the memory that is needed(low memory).
    - Hash tables are fast at retrieving data(low computations), but take up a lot of memory to allow all possible states of the hash output(high memory).
    - What if you could put the data in an array(low memory) and encode the position of that data in an equation. Then when retrieving the data you just have to run the equation(low computations) to get the exact position.



- JS Frameworks
- Javascript, HTML, CSS
- Browser
---------------------------------------
- Communication protocols
    - HTTPS, SSH, FTP, SMTP, etc.
    - TCP, UDP
    - IP
- C++, node, python, rust, java, go, etc.
- C
- Assembly
- Operating system
- Machine code
- Modules
- Latches and flip flops
- Logic gates
- Transistors
--------------------------------------
- B-tree
- Binary tree
- Binary Search tree
- AVL Tree
- Red-Black Tree
- Graph
- Trie
- Priority Queue vs Que?
