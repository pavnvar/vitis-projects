## Example initiation interval

This example shows the effect of the initiation interval ("II") on the total cycle count of a pipelined loop.

1. Open the synth report and notice two things:
  - The total "latency" of the loop should be roughly equal to L + N, where L is the latency of the pipeline and N is the number of iterations.
  - The instantiated compute units: one addition unit, one subtraction unit, and one multiplication unit.
2. Now change the II to 2 and re-generate the report.
  - Observe how the cycle count now scales as L + 2N.
  - The number of instantiated compute units has now been reduced to a single addition/subtraction unit, and the multiplication unit. 
3. You can play with both the II and N to see the affect on the cycle count.
