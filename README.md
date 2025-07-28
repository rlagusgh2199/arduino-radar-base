# 🛰️ 초음파 레이더 기지 (Ultrasonic Radar Base)

Arduino 기반으로 초음파 센서와 서보모터를 활용한 레이더 시스템입니다.  
실시간 물체 탐지, 경고 알림, 시각화까지 가능하도록 구현하였습니다.  
군 복무 중 체득한 레이더 기술에 대한 실전 경험을 바탕으로 기획한 작품입니다.

---

## 📌 프로젝트 개요

| 항목 | 내용 |
|------|------|
| 🧑‍💻 개발자 | 김현호 |
| 🕰️ 개발 기간 | 2023.05 |
| 💡 개발 목적 | 레이더 기지의 원리를 아두이노 기반으로 재현하고, 실시간 경고/시각화 기능까지 포함한 방어체계 모사 시스템 제작 |
| 🛠️ 주요 기능 | 물체 감지, 위험 경고, 자동 회전 레이더, 수동 정지, 실시간 시각화 (Processing) |
| 💬 사용 언어 | Arduino C, Processing(Java 기반) |

---

## ⚙️ 사용 기술 및 부품

### 🧩 Hardware
- 초음파 센서 (HC-SR04)
- 서보모터 (SG90)
- LCD (I2C)
- 부저, LED
- tact 스위치 (→ 사용 안 함), IR 리모컨(충돌로 제외)

### 🧠 Software
- Arduino IDE
- Processing (for visualization)
- Serial 통신

---

## 🧩 주요 기능

| 기능 | 설명 |
|------|------|
| 📡 물체 거리 탐지 | 초음파 센서를 통해 거리 측정 |
| 🧭 회전 탐지 범위 확대 | 서보모터를 0~180도 자동 회전 |
| 🚨 위험 경고 시스템 | 10cm 이내 접근 시 LED + 부저 + LCD 표시 |
| 🖥️ 실시간 시각화 | Processing 기반 레이더 UI로 출력 |
| 🧷 모터 멈춤 모드 | Serial 입력 '0' 입력 시 정지 가능 |

---

## 🎥 시연 영상

👉 [시연 영상 보러가기](여기에_영상_URL_삽입)

---

## 🧪 실행 방법

### 하드웨어 연결
- 초음파 센서 → 핀 12(ECHO), 13(TRIG)
- 서보모터 → 핀 8
- 부저 → 핀 7
- LED → 핀 4
- LCD → I2C

### 실행 순서
1. `arduino_main.ino` 업로드
2. Processing 실행 후 `radar_visualization.pde` 열기
3. `COM4` 또는 자신의 포트 설정
4. 실행하면 시각화 가능

---

## 🗂️ 폴더 구조

```
arduino-radar-base/
├── arduino_main.ino
├── radar_visualization.pde
├── README.md
├── /docs
│   ├── dev_plan.docx
│   ├── final_report.docx
│   └── progress_report.docx
├── /images
│   ├── circuit_diagram.jpg
│   └── demo_photo.jpg
└── /video
    └── 시연영상_URL.txt
```

---

## ⚠️ 문제 해결 및 배운 점

- IR 리모컨과 tone/servo 라이브러리 충돌 → 사용 제외
- delay() 사용 시 서보모터 멈춤 문제 → tone() 한음으로 대체
- Serial 입력 기반 수동 정지 기능 추가
- 라이브러리 충돌 문제를 해결하며 타이머 자원 이해도 상승

---

## 🌱 향후 개선 방향

- 감지 거리 확장 (40cm → 1m)
- 더 다양한 시각화 (컬러, 원형 형태 등)
- 물체 형태 식별 기능 추가
- 자동 추적 시스템 고도화
- 하드웨어 외형 개선

---

## 🔗 참고 자료

- [How To Mechatronics – Arduino Radar Project](https://howtomechatronics.com/projects/arduino-radar-project/)
- [타이머 충돌 관련 포럼](https://cafe.naver.com/arduinostory/150117)
- [레이더 아이디어 블로그](https://blog.naver.com/cylogic/222173463388)
