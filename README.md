# 🎓 AutoGrade — Automated Term Work Assessment System

> A smart, parameter-driven system for objective, transparent, and bias-free evaluation of student term work.

---

## 📌 Problem Statement

Design a mini project for **automated Term Work assessment** of students based on parameters like:

- Daily Attendance
- Unit Test / Prelim Performance
- Student Achievements (if any)
- Mock Practical

---

## 🚀 Overview

**AutoGrade** is a single-page web application that automates the calculation of term work marks for students. It replaces manual, error-prone assessment with a **transparent, weighted formula** — ensuring every student is evaluated on the same objective rubric.

Teachers simply enter raw marks for each parameter, and the system instantly computes the **weighted term work score (out of 100)** and assigns a **grade**.

---

## ✨ Features

| Feature | Description |
|---------|-------------|
| **📅 Attendance Tracker** | Enter days present / total working days → auto-calculates attendance percentage |
| **📝 Unit Test Aggregation** | Supports Unit Test + Prelim marks with separate "out of" fields; averages both into a combined score |
| **🏆 Achievement Scoring** | Dropdown-based tiered scoring for Technical (Hackathons, Papers) and Extracurricular (Sports, NSS/NCC, Cultural) |
| **🔬 Mock Practical** | Three sub-components: Experiment Performance, Lab Record/Journal, and Viva Voce |
| **⚡ Real-Time Calculation** | Score and grade update instantly as you type — no submit button needed |
| **💾 Save Reports** | Save student assessments to an in-session leaderboard |
| **🏅 Leaderboard** | All saved students ranked by score with rank badges (#1 gold, #2 silver, #3 bronze) |
| **🔍 View Report Modal** | Click "View" on any saved student to see a detailed score card with bar charts |
| **🗑️ Delete Reports** | Remove any saved report from the leaderboard |
| **👑 Top Performer Banner** | The highest-scoring student is always highlighted at the top |
| **📱 Responsive Design** | Works on desktop, tablet, and mobile screens |
| **🎨 Premium Dark UI** | Animated background blobs, glassmorphism, micro-animations, and modern typography |

---

## 📐 Scoring Formula

All parameters are first **normalised to a 0–100 scale**, then the weighted formula is applied:

```
TW = (A × 0.25) + (UT × 0.40) + (Ach × 0.20) + (MP × 0.15)
```

| Symbol | Parameter | Weight | Max Marks |
|--------|-----------|--------|-----------|
| **A** | Daily Attendance (%) | 25% | 25 |
| **UT** | Unit Test / Prelim (average %) | 40% | 40 |
| **Ach** | Student Achievements (tiered %) | 20% | 20 |
| **MP** | Mock Practical (composite %) | 15% | 15 |

### Sub-Calculations

- **Attendance**: `(Days Present ÷ Total Working Days) × 100`
- **Unit Test**: `Average of (UT1 Marks ÷ UT1 Max × 100) and (Prelim Marks ÷ Prelim Max × 100)`
- **Achievements**: `Average of Technical Score and Extracurricular Score` (each 0–100 tiered)
- **Mock Practical**: `Average of (Experiment ÷ Max) + (Lab Record ÷ Max) + (Viva ÷ Max) × 100`

---

## 📊 Grading Scale

| Score Range | Grade | Status |
|:-----------:|:-----:|--------|
| 90 – 100 | **O** (Outstanding) | ✅ Pass |
| 80 – 89 | **A+** | ✅ Pass |
| 70 – 79 | **A** | ✅ Pass |
| 60 – 69 | **B+** | ✅ Pass |
| 50 – 59 | **B** | ⚠️ Average |
| 40 – 49 | **C** | ⚠️ Average |
| Below 40 | **F** (Fail) | ❌ At Risk |

---

## 🛠️ Tech Stack

| Technology | Purpose |
|------------|---------|
| **HTML5** | Semantic page structure |
| **CSS3** | Custom properties, animations, glassmorphism, responsive grid |
| **Vanilla JavaScript** | Real-time calculation, DOM manipulation, report management |
| **Google Fonts** | Syne (headings), DM Mono (body), Fraunces (accents) |

> **No frameworks, no build tools, no dependencies.** Just open `index.html` in any modern browser.

---

## 📂 Project Structure

```
AutoGrade/
├── index.html      # Complete single-page application (HTML + CSS + JS)
└── README.md       # Project documentation (this file)
```

---

## 🖥️ How to Run

1. **Clone or download** this project to your machine.
2. **Open** `index.html` in any modern web browser (Chrome, Firefox, Edge, Safari).
3. That's it! No server, no installation, no setup required.

```bash
# Or from the command line:
start index.html          # Windows
open index.html           # macOS
xdg-open index.html       # Linux
```

---

## 📖 How to Use

### Step 1 — Enter Student Details
Fill in the **Student Name** and **Roll Number** at the top of the calculator.

### Step 2 — Input Parameter Marks
- **Attendance**: Enter days present and total working days.
- **Unit Test / Prelim**: Enter marks obtained and maximum marks for both.
- **Achievements**: Select the appropriate tier from the dropdowns.
- **Mock Practical**: Enter marks for Experiment, Lab Record, and Viva.

### Step 3 — View Results
The right panel shows the **live score**, **grade**, **per-parameter breakdown**, and **pass/fail status** — all updated in real time.

### Step 4 — Save & Compare
Click **💾 Save Report** to add the student to the leaderboard. Repeat for multiple students to compare rankings.

---

## 🔄 How It Works (Pipeline)

```
┌─────────────────┐     ┌──────────────────────┐     ┌───────────────────┐
│  Data Collection │ ──▶ │ Normalisation &       │ ──▶ │ Report Generation │
│                 │     │ Weighting             │     │                   │
│ • Attendance    │     │ • Scale to 0–100      │     │ • Score & Grade   │
│ • Unit Tests    │     │ • Apply formula       │     │ • Bar Charts      │
│ • Achievements  │     │ • Handle edge cases   │     │ • Leaderboard     │
│ • Mock Practical│     │                       │     │ • Status (P/F)    │
└─────────────────┘     └──────────────────────┘     └───────────────────┘
```

---

## 🎨 Design Highlights

- **Dark Theme** with CSS custom properties for easy theming
- **Animated gradient blobs** as background decoration
- **Subtle grid overlay** for a technical aesthetic
- **Floating card animation** on the hero visual
- **Animated progress bars** that grow on page load
- **Hover effects** on parameter cards and table rows
- **Glassmorphism** on the navigation bar
- **Save flash animation** on the save button
- **Smooth modal transitions** for report viewing

---

## 🧪 Sample Data

The app comes pre-loaded with 3 sample students for demonstration:

| Name | Roll | Score | Grade |
|------|------|-------|-------|
| Rohan Mehta | 12 | 94 | O |
| Priya Patel | 28 | 78 | A |
| Amit Singh | 05 | 48 | C |

---

## 📝 Future Enhancements

- [ ] LocalStorage persistence (retain saved reports across browser sessions)
- [ ] PDF export for individual student reports
- [ ] CSV import/export for bulk student data
- [ ] Class-wide analytics with charts (average, distribution, top/bottom performers)
- [ ] Dark / Light theme toggle
- [ ] Faculty login and authentication
- [ ] Database backend for permanent record storage

---

## 👥 Authors

- **Nihal Bora**

---

## 📄 License

This project is developed as a **Mini Project** for academic purposes.

---

<p align="center">
  <strong>AutoGrade</strong> · Built with transparency, fairness, and student growth in mind.
</p>
