# Algorithm Project 1
* * *
### 프로젝트 목표
* **정렬 알고리즘** 중 4가지의 알고리즘을를 구현하여 서로간의 성능을 분석  
  * **ShellSort**  
  * **Median-of-three QuickSort**  
  * **Odd-Even Transposition Sort**  
  * **BitonicSort**  
* **GPU**를 이용하는 **CUDA**라는 프로그램을 통하여 **Visual**과의 차이 또한 비교 및 분석
### 사용 Tool
- [x] Visual Studio  
- [x] CUDA  
### 프로젝트 결과 (간략)
<img src="/image/d1.png" width="700px" height="350px" alt="BlockDiagram"></img><br/><br/>
<img src="/image/d2.png" width="420px" height="350px" alt="BlockDiagram"></img><br/>
> **모든 Sort**를 서로 비교 및 분석한 결과 (데이터 개수 및 실행시간)  
> **Median-of-Three QuickSort < ShellSort < BitonicSort << Odd-EvenSort**  
> 특히, Mo3 QuickSort(**O(nlogn)**)과 Odd-EvenSort(**O(n^2)**)을 비교하면 확연한 차이가 나는 것을 확인  

<img src="/image/d3.png" width="700px" height="350px" alt="BlockDiagram"></img><br/><br/>
<img src="/image/d4.png" width="600px" height="200px" alt="BlockDiagram"></img><br/>
> Visual(**CPU**)와 CUDA(**GPU**)를 서로 비교 및 분석한 결과 (데이터 개수 및 실행시간)  
> **데이터 Set의 개수**가 증가하면 증가할수록 **GPU**가 **CPU**에 비하여 성능이 압도적으로 좋음을 확인
