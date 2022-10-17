# Lab 3

![](./img/final.png)

`Velocity Fit`: -1.3809e-7x<sup>6</sup> + 1.4718e-5x<sup>5</sup> - 0.0006x<sup>4</sup> + 0.0115x<sup>3</sup> - 0.0158x<sup>2</sup> + 2.7347x + 13.9818

`Derivative` (ae. acceleration): -8.2856e-7x<sup>5</sup> + 7.3589e-5x<sup>4</sup> - 0.0025x<sup>3</sup> + 0.0345x<sup>2</sup> - 0.0317x + 2.7347

a<sub>norubberband</sub> : (g * m<sub>h</sub>)/(m<sub>c</sub> + m<sub>h</sub>) => (980cm/s<sup>2</sup> * 300g) / (450g + 300g) = 392cm/s<sup>2</sup>

a<sub>derivative_flat_average</sub> : 279cm/s<sup>2</sup>

`% difference`: 28.8

a<sub>norubberband</sub> is larger than a<sub>derivative_flat_average</sub> as it should be because a<sub>norubberband</sub> is the maximum a<sub>derivative_flat_average</sub> can be given all other forces are negligible. Possibly, because we didn't take into account friction or the mass of the rubber band our experimental value is much lower than our theoretical value. Other reasons may include the precision of the instruments we measured with. Having us measure with a ruler instead of a piece of equipment that is more precise could have messed with our results and a faster spark thing would also give us clearer data. The rubber band has a meaningful impact on the velocity of the system. a<sub>derivative_flat_average</sub> is the average slope of the velocity from the interval [2, 30]. a<sub>ave</sub> is unbelievably noisy. From the graph it may look like you'd be able to tell that there's a general downward trend with respect to time but that's because the top part of the graph was truncated. If I only had a<sub>derivative_flat_average</sub> , it would be very difficult to tell how the acceleration was changing; however, using the derivative of velocity as the acceleration makes it pretty clear that from the time interval [2, 30] the acceleration is pretty constant and only after that does the rubber band start to affect the system.