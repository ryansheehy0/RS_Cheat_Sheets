# Dreaming Neural Net
An algorithm is simply a patter that maps inputs to outputs. It can be thought of as a way to compress data. For example, if you want to know where a throwing ball will land. You could keep track of all the data points. Each data point having a time, x/y/z position, and momentum. Or you could instead just know the starting data point of a ball, and use a equation to know where a ball will land. The equation allows you to compress the data.

There are certain problems that are so hard that it's almost impossible to find an algorithm to solve them. In order to solve these problems we created an algorithm to create other algorithms. By giving this algorithm a series of inputs and corresponding outputs, know as data, it learned the underlying patter that mapped the inputs to outputs, aka the underlying algorithm. The more high quality data, the more accurate the algorithm.

The hard part about using this algorithm for algorithms is how do we get high amounts of quality data. What if we could create an algorithm that could generate high amounts of quality data for us. Well, if we had such an algorithm, then we would have already solved the problem we are trying to solve.

What if we can give this algorithm for algorithms one correct input and output, then it can dream up another set of inputs and outputs and ask us if it's correct. It keeps repeating that until it understands everything it can from that initial input and output. This would cut down on the amount of data we would have to give it.

```
          +----------+
Input1 -> | Algo for | -> Output1 -+   +- Correct1
          | Algos 1  |             |   |
          +----------+             v   v
            |      ^               Error
            |      +-----------------+
            v
Dream     +----------+
Input1 <- | Algo for | <- Correct1
  +-----> | Algos 2  | -> Dream -----+   +- Correct2
          +----------+   Output1     v   v
            |      ^                 Error
            |      +-------------------+
            v
Dream     +----------+
Input2 <- | Algo for | <- Correct2
  +-----> | Algos 3  | -> Dream -----+   +- Correct3
          +----------+   Output2     v   v
            |      ^                 Error
            |      +-------------------+
            v
           Etc
```

- H - Human
- DNN - Dreaming Neural Net
	- H: Here's an example.
	- DNN: Do I have the correct idea?
	- H: No, here's what you did wrong.
	- DNN: Do I have the correct idea now?
	- ...
	- H: Yes. You got it.
- NN - Neural Net
	- H: Here's an example.
	- NN: Give me another example.
	- ...

Dreaming neural nets give more points around 1 area of the phase space until it has a good idea of that area. Then you can train it on another area of the phase space.

- Dreaming - Checking answers/solutions with an internal simulation.