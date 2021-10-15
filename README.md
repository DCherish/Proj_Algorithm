---

<div align="center">

 💜 *Algorithm Project 1*

</div>

---

# 🧐 프로젝트 목표
- **정렬 알고리즘** 중 4가지의 알고리즘을를 구현하여 서로 간의 성능을 분석  
  - `ShellSort` `Median-of-three QuickSort` `Odd-Even Transposition Sort` `BitonicSort`  
- **GPU**를 이용하는 **CUDA**라는 프로그램을 통하여 **Visual**(**CPU**)와의 차이 또한 비교 및 분석  

# 👨‍💻 사용 기술 Stack
- [x] Visual Studio  
- [x] CUDA  

# 💛 프로젝트 결과 (간략)
<img src="/image/d1.png" width="700px" height="350px" alt="BlockDiagram"></img><br/>
<img src="/image/d2.png" width="420px" height="350px" alt="BlockDiagram"></img><br/>
> **모든 Sort**를 서로 비교 및 분석한 결과 (데이터 개수 및 실행시간)  

👉 **Median-of-Three QuickSort < ShellSort < BitonicSort << Odd-EvenSort**  
👉 특히, Mo3 QuickSort(**O(nlogn)**)와 Odd-EvenSort(**O(n^2)**)를 비교하면 확연한 차이가 나는 것을 확인  

---

<img src="/image/d3.png" width="700px" height="350px" alt="BlockDiagram"></img><br/>
<img src="/image/d4.png" width="650px" height="200px" alt="BlockDiagram"></img><br/>
> CUDA(**GPU**)와 Visual(**CPU**)을 서로 비교 및 분석한 결과 (데이터 개수 및 실행시간)  

👉 **CUDA(GPU) < Visual(CPU)**  
👉 **데이터 Set의 개수**가 **증가**할수록 **GPU**가 **CPU**에 비하여 성능이 압도적으로 좋음을 확인  

---

# ⚠️ License
The theme is available as open source under the terms of the [MIT License](https://github.com/DCherish/Proj_Algorithm/blob/master/LICENSE).  
###### *When you use this project, It would appreciate it if you could press the Star button*(⭐).

---
