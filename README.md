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


![TableLBYARCH2](https://github.com/Bredrumb/LBYARCH_MCO2_SAXPY/assets/83742598/c4f22754-d037-4c14-ad7b-276cb22d3a5a)

### Release Mode Results
The following table shows the average run time (in milliseconds) for each implementation:

![TableLBYARCH](https://github.com/Bredrumb/LBYARCH_MCO2_SAXPY/assets/83742598/ba40cb3b-fd96-4ecd-a37c-5b4363f17c5c)




### Debug Mode Analysis

The ASM Kernel and C Kernel implementations operate similarly in Debug Mode for varying input vector sizes. On the other hand, the ASM Kernel regularly displays marginally shorter average run times than the C Kernel. This might be explained by assembly language allowing for lower-level optimizations that lead to more effective code execution.

In Debug Mode, for 2^20-sized vectors, the ASM Kernel exhibits a 33.33% improvement over the C Kernel. For 2^24-sized vectors, the ASM Kernel demonstrates a 4.35% improvement over the C Kernel. Similarly, for 2^26-sized vectors, the ASM Kernel shows a 2.26% improvement over the C Kernel.

### Release Mode Analysis

When comparing the C Kernel and ASM Kernel implementations in Release Mode to Debug Mode, notable performance improvements are seen. Once more, for all vector sizes, the average run time of the ASM Kernel is often lower than that of the C Kernel. 

In Release Mode, for 2^20-sized vectors, the ASM Kernel displays a 100% improvement over the C Kernel. For 2^24-sized vectors, the ASM Kernel exhibits a 42.11% improvement over the C Kernel. Likewise, for 2^26-sized vectors, the ASM Kernel shows a 22.22% improvement over the C Kernel

The performance analysis indicates that the ASM Kernel implementation offers better execution times than the C Kernel, particularly in Release Mode. 

### Graph
![LBYARCH MP2 CODE](https://github.com/Bredrumb/LBYARCH_MCO2_SAXPY/assets/83742598/2a3dbeb9-3fe0-41fd-b711-64246c7ecd1a)
