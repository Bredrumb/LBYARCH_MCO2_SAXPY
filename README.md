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

The following table shows the average run time (in milliseconds) for each implementation in Debug Mode:

<table style="background-color: white;">
  <tr>
    <th>Size of Vectors</th>
    <th>C Kernel</th>
    <th>ASM Kernel</th>
  </tr>
  <tr>
    <td>2^20</td>
    <td>3</td>
    <td>2</td>
  </tr>
  <tr>
    <td>2^24</td>
    <td>46</td>
    <td>44</td>
  </tr>
  <tr>
    <td>2^26</td>
    <td>177</td>
    <td>173</td>
  </tr>
</table>

### Release Mode Results

The following table shows the average run time (in milliseconds) for each implementation in Release Mode:

<table style="background-color: white;">
  <tr>
    <th>Size of Vectors</th>
    <th>C Kernel</th>
    <th>ASM Kernel</th>
  </tr>
  <tr>
    <td>2^20</td>
    <td>1</td>
    <td>0</td>
  </tr>
  <tr>
    <td>2^24</td>
    <td>19</td>
    <td>11</td>
  </tr>
  <tr>
    <td>2^26</td>
    <td>63</td>
    <td>49</td>
  </tr>
</table>
