# **Comparative Execution Time**

The performance of the C Kernel and ASM Kernel implementations was tested in both Debug Mode and Release Mode across different sizes of input vectors.
 ## Debug Mode Results

### Debug Mode Result for 2^20 Vector Size
![Debug Mode Result for 2^20](DebugModeResult20.jpg)


### Debug Mode Result for 2^24 Vector Size
![Debug Mode Result for 2^24](DebugModeResult24.jpg)


### Debug Mode Result for 2^26 Vector Size
![Debug Mode Result for 2^26](DebugModeResult26.jpg)


## Release  Mode Results
 
### Release Mode Result for 2^20 Vector Size
![Release Mode Result for 2^20](ReleaseModeResult20.jpg)

### Release Mode Result for 2^24 Vector Size
![Release Mode Result for 2^24](ReleaseModeResult24.jpg)

### Release Mode Result for 2^26 Vector Size
![Release Mode Result for 2^26](ReleaseModeResult26.jpg)


### Debug Mode Results
The following table shows the average run time (in milliseconds) for each implementation:


| Size of Vectors | C Kernel | ASM Kernel |
|-----------------|----------|------------|
| 2^20            | 3        | 2          |
| 2^24            | 46       | 44         |
| 2^26            | 177      | 173        |

### Release Mode Results
The following table shows the average run time (in milliseconds) for each implementation:


| Size of Vectors | C Kernel | ASM Kernel |
|-----------------|----------|------------|
| 2^20            | 1        | 0          |
| 2^24            | 19       | 11         |
| 2^26            | 63       | 49         |


### Debug Mode Analysis

The ASM Kernel and C Kernel implementations operate similarly in Debug Mode for varying input vector sizes. On the other hand, the ASM Kernel regularly displays marginally shorter average run times than the C Kernel. This might be explained by assembly language allowing for lower-level optimizations that lead to more effective code execution.

### Release Mode Analysis

When comparing the C Kernel and ASM Kernel implementations in Release Mode to Debug Mode, notable performance improvements are seen. Once more, for all vector sizes, the average run time of the ASM Kernel is often lower than that of the C Kernel. 

The performance analysis indicates that the ASM Kernel implementation offers better execution times than the C Kernel, particularly in Release Mode. 
