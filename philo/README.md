*This project has been created as part of the 42 curriculum by mtran-nh.*

**Description**
- **Project:**: A concurrent implementation of the Dining Philosophers problem using POSIX threads and mutexes.
- **Goal:**: Practice concurrency control, synchronization primitives, and safe thread interactions. The program simulates philosophers who alternately think, take forks, eat, and sleep while preventing data races and handling termination when a philosopher dies or when a meal limit is reached.

**Instructions**
- **Compile:**: Run `make` at the project root. This produces the executable `philo`.
- **Usage:**: `./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]`
  - `number_of_philosophers` — total philosophers (int > 0)
  - `time_to_die` — time (ms) after which a philosopher dies if they don't start eating
  - `time_to_eat` — time (ms) a philosopher spends eating
  - `time_to_sleep` — time (ms) a philosopher spends sleeping
  - `number_of_times_each_philosopher_must_eat` (optional) — program ends when each philosopher has eaten this many times
- **Example:** `./philo 5 800 200 200` — run 5 philosophers with the times above.

**Behavior & Notes**
- **Termination:** The program prints actions to stdout and terminates when a philosopher dies or when the optional meal count is reached.
- **Single philosopher case:** Special handling avoids deadlock when `number_of_philosophers` is 1.
- **Important files:**
  - [includes/philo.h](includes/philo.h) — main project header
  - [src/main.c](src/main.c) — program entry
  - [src/init.c](src/init.c) — initialization logic
  - [src/simulation.c](src/simulation.c) — thread loop and monitoring
  - [src/action.c](src/action.c) — actions (take forks, eat, sleep)
  - [src/get_data.c](src/get_data.c), [src/utils.c](src/utils.c), [src/string.c](src/string.c)

**Resources**
- **Dining Philosophers (classic):** https://en.wikipedia.org/wiki/Dining_philosophers_problem
- **POSIX threads (pthreads) reference:** https://man7.org/linux/man-pages/man7/pthreads.7.html
- **gettimeofday / usleep references:** system man pages and online docs
- **Tutorials & Articles:** Various concurrency tutorials on mutexes and condition variables

**AI Usage Disclosure**
- An AI assistant was used to draft and structure this `README.md` and to suggest small code-style improvements. All code changes and final edits were performed and reviewed by the project author.

**License & Notes**
- This is a student project created for educational purposes as part of the 42 curriculum.

If you want, I can also add a short `RUN.md` with example runs and sample outputs, or update the `Makefile` with additional targets.
