#  Philosophers

**Philosophers** is a concurrency project from [42 School](https://42.fr/) that simulates the classic **Dining Philosophers Problem**, where multiple philosophers alternately eat, think, and sleep using shared forks. The goal is to manage resource sharing and avoid deadlocks, race conditions, or starvation.

---

##  How to Compile

```
make
```

---

##  Usage

```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

* `number_of_philosophers`: Number of philosophers and forks
* `time_to_die`: Time (ms) a philosopher can live without eating
* `time_to_eat`: Time (ms) it takes to eat
* `time_to_sleep`: Time (ms) spent sleeping
* `number_of_times_each_philosopher_must_eat` (optional): Stops simulation when each philosopher has eaten this many times

### Example

```
./philo 5 800 200 200 [4]
```

## Rules & Goals

* Each philosopher must take **two forks** to eat.
* A philosopher dies if they don't eat within `time_to_die`.
* You must **prevent deadlocks** and **data races** using mutexes.

### Philosophers (Bonus)

This bonus implementation uses **processes** and **semaphores** to solve the Dining Philosophers problem.
Each philosopher is a separate process that handles its own lifecycle (eating, sleeping, thinking) and shares forks via semaphores. 
Death and fullness are monitored with additional threads and semaphores.

Features:

* Process-based parallelism
* Semaphore-protected forks and output
* Optional monitoring for philosopher death and meals
