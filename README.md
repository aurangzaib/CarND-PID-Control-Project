# PID Control (PIDC) Project


| **Source Code**  | [https://github.com/aurangzaib/CarND-PID-Control-Project](https://github.com/aurangzaib/CarND-PID-Control-Project)  |
|:-----------|:-------------|
| **Overview**  | `README.md`  |
| **Setup**  | `SETUP.md`  |
| **PID Implementation**| `src/PID.cpp`|
| **How to run**  | `mkdir build && cd build` | 
| |`cmake .. && make`     |
| |`./pid`     |


## Introduction:

PID Controller is used to estimate optimized `throttle`, `steering` using Cross Track Error `CTE` and velocity `v`.

The steps of the project are as following:

- Read `cte` and `v` from simulator

- Initialize PID parameter `Kp, Kd, Ki`

- Update PID Errors using CTE for steering and throttle

- Calculate steering value

- Calculate throttle value


## Explanation of the code:

The implementation of PID Project is divided into 2 files:

`main.cpp`

`pid.cpp`

Following table summarizes the purpose of each file:

| File | Explanation |
|:-----------|:-------------|
|**main.cpp**| |
|| Initialize PID controllers for steering and throttle values |
||Get cross track error `cte` and velocity `v` from client i.e. simulator|
||Update PID errors using `cte` for steering and throttle controllers |
||Get updated steering and throttle values|
||Pass values to simulator|
|**pid.cpp**| |
||Implement PID initialization method `Init` |
||Implement PID errors update method `UpdateError` |
||Implement steering value calculation method `CalculateSteering` |
||Implement throttle value calculation method `CalculateThrottle` |

## Hyperparameters in PID

The tuning of the parameters is done in the following way:

- Set `Kd` and `Ki` to 0. Tune `Kp` so that car comes to reference trajectory. At this point, car keeps crossing zero point (where `CTE` is 0) but there are oscillations and oscillations keep increasing with time

- `Ki` is tuned so that the system bias as well increasing oscillation with time can be handled. At this point, car no longer has drift issues and oscillation doesn't keep increasing but still there are oscillations

-  `Kd` is tuned to remove the oscillations as much as possible by damping them. At this point, car drives with minimum `CTE`, minimum oscillations and minimum drift


Following hyperparemters are used in MPC

| Param | Symbol | Value |
|:-----------|:-------------|:-------------|
|**Steering PID controller**||
|Propotional Gain|Kp|0.140|
|Differential Gain|Kd|0.000270736|
|Integral Gain|Ki|6.10|
|**Throttle PID controller**||
|Propotional Gain|Kp|0.30|
|Differential Gain|Kd|0.052|
|Integral Gain|Ki|0|

## Results

Following points sum up the results and conclusion for PID Controller:

- PID controller, although simpler to implement, has issues with completely damping the oscillations of front wheels of the car

- Twiddle can be used to improve the Gains (`Kp, Kd, Ki`) but in real world it is rarely used and other methods are preferred e.g. Adaptive Sampler

- It doesn't provide control of different variables and parameters of a car. For example, wheel turn, wheel turn rate, accelerartion profile, car orientation etc

- As PID has no concept of Predicton Horizon, it is not possible to predict the future events and adjust PID actuations accordingly

- It can't deal with actuation latency which is around 100ms in real world



The video (GIF) below shows results of PID Controller:


![Results](result-pid.gif)
