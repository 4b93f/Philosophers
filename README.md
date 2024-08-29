# Philosophers

The `Philosophers` project is a simulation of the classic **Dining Philosophers Problem**, a well-known problem in computer science that illustrates synchronization issues and solutions in concurrent programming. The project is part of the 42 school curriculum, aiming to provide experience in handling multithreading, process synchronization, and resource management in C.

## Table of Contents
- [Philosophers](#philosophers)
	- [Table of Contents](#table-of-contents)
	- [About the Project](#about-the-project)
	- [Features](#features)
	- [Problem Description](#problem-description)
	- [Getting Started](#getting-started)
		- [Prerequisites](#prerequisites)
		- [Installation](#installation)

## About the Project

The `Philosophers` project is designed to simulate a common concurrency problem where a certain number of philosophers sit around a table, each alternating between thinking, eating, and sleeping. The challenge is to ensure that the simulation avoids deadlock and starvation, and properly synchronizes access to shared resources (forks) using threads and mutexes.

## Features

- Simulate the Dining Philosophers problem using multithreading.
- Prevent deadlocks and starvation through careful synchronization.
- Configurable number of philosophers, time to eat, sleep, and die.
- Real-time logging of the philosophers' states (thinking, eating, sleeping, died).

## Problem Description

In the Dining Philosophers problem:
- There are `N` philosophers seated around a circular table.
- Each philosopher alternates between three states: **thinking**, **eating**, and **sleeping**.
- To eat, each philosopher requires two forks (one on the left and one on the right).
- A fork can be picked up by only one philosopher at a time and must be released after eating.
- The objective is to create a simulation that avoids deadlocks (where no progress is made because all resources are in use) and starvation (where a philosopher never gets to eat).

## Getting Started

### Prerequisites

- **gcc** or another C compiler.
- **Make** build tool.
- **POSIX Threads (pthreads)** library for threading support.

### Installation

1. **Clone the repository:**

   ```bash
   git clone https://github.com/4b93f/Philosophers.git
   cd Philosophers

### Usage
```
./philosophers <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep [number_of_times_each_philosopher_must_eat]
