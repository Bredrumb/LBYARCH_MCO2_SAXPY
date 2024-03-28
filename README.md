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


