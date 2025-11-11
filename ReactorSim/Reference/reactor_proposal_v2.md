# Nuclear Reactor Control Panel Simulator 🏭⚛️

//TODO part 2 & rest of 3

## Project Overview

A real-time analog-style nuclear reactor control panel simulation game built in C++ with Raylib. Players manage a
pressurized water reactor through an authentic control interface featuring gauges, switches/buttons, and sliders
controlled
entirely by mouse. The simulation (somewhat) models a PWR reactor's physics. Players must balance power generation
with the reactor's limitations in mind, while responding to random events and meeting grid demands
to earn revenue. The analog control panel aesthetic provides an immersive 1970s-era nuclear plant operator experience.

---

## 1. Basic Requirements (1 mark each ➡️ 14 marks)

**1.1** Spreadsheet tracking completion of features/requirements with automatic score calculation.

**1.2** Two self-imposed milestone Wednesdays with mapped features for each demonstration session.

**1.3** Mermaid Diagram showing the functional layout of the planned codebase.

**1.4** Reactor core pressure display in Kilopascals (with basic indications of safe operating threshold).

**1.5** Control rod position slider (0–100%) with mouse drag interaction.

**1.6** Coolant system with flow rate variable and pump speed slider control (0–100%) that affects heat removal rate
from reactorcore and to steam turbine.

**1.7** Reactor core temperature display in Celsius (with basic indications of safe operating threshold).

**1.8** Turbine RPM display (0-2000 RPM) 1800 RPM is ideal.

**1.9** SCRAM button shuts off reactor by setting control rods to 100% insertion

**1.10** Generator electrical power output display showing megawatts electrical (MWe) produced 8 segment display.

**1.11** Score system: Score increases when within (0-100MWe) to the target power ouput, increase scales with accuracy

**1.12** Basic loss condition: Reactor meltdown occurs when core temperature exceeds 800°C or Reactor explodes if
pressure hits 20 MPa.

**1.13** Reset button that restarts simulation with default initial conditions

**1.14** Game timer displayed as MM:SS format that starts when reactor power exceeds 100 MW and stops on win/loss
conditions.

---

## 2. Intermediate Requirements (2 marks each ➡️ 22 marks)

**2.1** Turbine RPM gauge with analog needle display showing rotational speed (0-2000 RPM) where RPM is calculated from
steam flow: `RPM = steam_valve_position × power_output × 2.0`.

**2.2** Steam valve control slider (0-100%) that regulates steam flow to turbines, directly affecting turbine RPM and
electrical power output with visual valve position indicator.

**2.3** Heat transfer system modeling heat flow from reactor core through coolant:
`heat_generated = power_output × 0.9`, `heat_removed = coolant_flow × (core_temp - 280) × 0.01`,
`temp_change = (heat_in - heat_out) × delta_time`.

**2.4** System pressure gauge displaying coolant pressure in MPa (0-20 range) calculated from core temperature:
`pressure = 15.0 + (temperature - 300) × 0.03`, with red-line danger zone marked above 18 MPa.

**2.5** Warning indicator light system with three status lights: Green "NORMAL" (temp < 550°C), Yellow "CAUTION" (temp
550-700°C), Red "DANGER" (temp > 700°C or pressure > 17 MPa).

**2.6** Grid demand system with analog meter showing target power output (randomly set between 300-800 MWe) that changes
every 45 seconds, with green/red indicator light showing demand fulfillment status (green = within ±50 MW).

**2.7** Revenue counter displaying accumulated earnings ($) where successfully meeting grid demand earns $10/second,
while missing demand earns $0/second. Counter updates in real-time.

**2.8** Emergency Cooling System (ECCS) implemented as toggle switch that activates high-flow coolant injection,
increasing heat removal by 3× for rapid temperature reduction. ECCS has limited capacity shown on reserve gauge (100% →
0%, depletes at 10%/second when active).

**2.9** Random event core system that triggers events every 60-90 seconds during gameplay, with event notification
banner displaying current active event name and countdown timer. Includes implementation of 2 basic events: "Coolant
Pump Degradation" (pump effectiveness reduced to 40%) and "Grid Demand Fluctuation" (demand changes every 15 seconds
with ±100 MW variance).

**2.10** Additional random events implemented: "Control Rod Sluggishness" (control rod slider moves at 50% normal speed
requiring doubled mouse drag distance) and "Steam Valve Stuck" (steam valve frozen at current position with valve slider
disabled and red indicator light).

**2.11** Additional random events implemented: "Temperature Sensor Malfunction" (temperature gauge displays random
fluctuations ±30°C from true value, updating every 2 seconds with flickering needle) and "Pressure Spike" (base pressure
increased by +3 MPa for event duration).

---

## 3. Advanced Requirements (3-4 marks each ➡️ 14 marks)

**3.1** Sound effects package including: control interaction clicks, continuous reactor hum (pitch varies with power),
alarm beeps (slow for yellow warning, rapid for red danger), SCRAM button clunk, grid demand change chime, and event
notification sound. **(3 marks)**

**3.2** Tutorial mode with guided 4-step sequence teaching: (1) Adjust control rods to increase power, (2) Start coolant
pump, (3) Open steam valve to generate electricity, (4) Execute SCRAM shutdown. Text overlays with arrows point to
specific controls, checkmarks indicate step completion. Timer does not start yet. **(4 marks)**

**3.3** Change all displays to use Analog-style gauge or dial style displays, this includes making a display class **(4
marks)**

**3.4** Post-game statistics screen showing detailed (Choose some of the following) session breakdown: total time,
revenue earned, number of events encountered, times ECCS was used, highest temperature reached, average power output,
and demand fulfillment percentage.
**(3 marks)**

---

## Random Events System (Requirements 2.9, 2.10, 2.11 Detail)

### Event Trigger Mechanism

- FirstEvent triggers 60-90 seconds after reactor startup (power > 100 MW)
- Subsequent events trigger 60-90 seconds after previous event ends
- Only one event active at a time
- Event duration: 30-45 seconds
- Events chosen randomly from pool with equal probability

### Event Pool (6 Events Total)

**Implemented in 2.9 (Core System):**

**Event 1: "Coolant Pump Degradation"**

- Effect: Coolant pump effectiveness reduced to 40% of slider position
- Player challenge: Must increase pump slider or reduce power to maintain cooling
- Visual: Yellow warning light on coolant section

**Event 2: "Grid Demand Fluctuation"**

- Effect: Grid demand changes every 15 seconds (instead of 45) with ±100 MW variance
- Player challenge: Rapid demand shifts require constant adjustment
- Visual: Demand meter updates rapidly with audio chime on each change

**Implemented in 2.10:**

**Event 3: "Control Rod Sluggishness"**

- Effect: Control rod slider moves at 50% normal speed (doubled mouse drag distance required)
- Player challenge: Sluggish control response makes adjustments difficult
- Visual: No additional indicator (player discovers through interaction)

**Event 4: "Steam Valve Stuck"**

- Effect: Steam valve frozen at current position for event duration
- Player challenge: Must adjust power/demand using only reactor controls
- Visual: Red indicator light on turbine section, valve slider disabled

**Implemented in 2.11:**

**Event 5: "Temperature Sensor Malfunction"**

- Effect: Temperature gauge displays random fluctuations (±30°C from true value) updating every 2 seconds
- Player challenge: Must operate reactor with unreliable temperature reading, use pressure as backup indicator
- Visual: Flickering temperature gauge needle

**Event 6: "Pressure Spike"**

- Effect: Base pressure increased by +3 MPa for event duration
- Player challenge: Must reduce power or increase cooling to prevent exceeding 18 MPa limit
- Visual: Pressure gauge enters yellow/red zones more easily

### Event Notification Display

```
┌────────────────────────────────────────────┐
│ ⚠️ EVENT: Coolant Pump Degradation [00:35] │
└────────────────────────────────────────────┘
```

---

## Simplified Physics Formulas

### Core Temperature

```cpp
float heat_generated = power_output * 0.9f;
float cooling_factor = pump_speed / 100.0f; // Modified by events
float heat_removed = coolant_flow * cooling_factor * (temperature - 280.0f) * 0.01f;
float temp_change = (heat_generated - heat_removed) * delta_time;
temperature += temp_change;
temperature = fmax(temperature, 280.0f); // Minimum ambient temp
```

### Reactor Power Output

```cpp
power_output = rod_effectiveness * 1000.0f; // Max 1000 MW thermal
power_output = fmax(power_output, 0.0f);
```

### System Pressure

```cpp
float base_pressure = 15.0f; // MPa
float temp_contribution = (temperature - 300.0f) * 0.03f;
pressure = base_pressure + temp_contribution + event_pressure_bonus;
pressure = fmax(pressure, 15.0f);

// Auto pressure relief
if (pressure > 18.0f) {
    relief_valve_open = true;
    pressure = 18.0f; // Clamped by relief
}
```

### Turbine RPM

```cpp
float steam_power = (steam_valve / 100.0f) * power_output;
turbine_rpm = steam_power * 2.0f; // Direct calculation
turbine_rpm = fmin(turbine_rpm, 2000.0f); // Max RPM limit
```

### Electrical Output

```cpp
float thermal_to_electrical = 0.35f; // 35% efficiency
float valve_factor = steam_valve / 100.0f;
electrical_output = power_output * valve_factor * thermal_to_electrical;
```

### Grid Demand & Revenue

```cpp
// Update demand timer
demand_timer -= delta_time;
if (demand_timer <= 0.0f || grid_event_active) {
    target_power = random_float(300.0f, 800.0f);
    demand_timer = grid_event_active ? 15.0f : 45.0f;
}

// Revenue calculation
float power_difference = fabs(electrical_output - target_power);
if (power_difference <= 50.0f) {
    revenue += 10.0f * delta_time; // $10/second when meeting demand
}
```

### ECCS Operation

```cpp
if (eccs_active && eccs_reserve > 0.0f) {
    heat_removed *= 3.0f; // Triple cooling effectiveness
    eccs_reserve -= 10.0f * delta_time; // Depletes at 10%/sec
    eccs_reserve = fmax(eccs_reserve, 0.0f);
    
    if (eccs_reserve <= 0.0f) {
        eccs_active = false; // Auto-shutoff when depleted
    }
}
```

---

## Control Panel UI Layout (1920×1080)

```
┌──────────────────────────────────────────────────────────────────┐
│  [EVENT BANNER: Current Event Name + Timer]        [TIMER][$$$$] │
├──────────────────────────────────────────────────────────────────┤
│                                                                  │
│  ┌────REACTOR CORE─────┐  ┌────COOLANT──────┐  ┌──TURBINE/GEN──┐ │
│  │                     │  │                 │  │               │ │
│  │  [TEMP GAUGE]       │  │  [PRESSURE]     │  │  [RPM GAUGE]  │ │
│  │    ___●___          │  │    ___●___      │  │    ___●___    │ │
│  │   /       \         │  │   /       \     │  │   /       \   │ │
│  │  |   550°C |        │  │  |  16 MPa |    │  │  | 1200rpm|   │ │
│  │   \_______/         │  │   \_______/     │  │   \_______/   │ │
│  │                     │  │                 │  │               │ │
│  │  [POWER GAUGE]      │  │  ●●● Status     │  │  [STEAM PRESS]│ │
│  │    ___●___          │  │  [G][Y][R]      │  │    ___●___    │ │
│  │   /       \         │  │                 │  │   /       \   │ │
│  │  |  650 MW |        │  │  [PUMP SPEED]   │  │  | 8.5 MPa|   │ │
│  │   \_______/         │  │  ○────────●───  │  │   \_______/   │ │
│  │                     │  │                 │  │               │ │
│  │  [CONTROL RODS]     │  │  [ECCS SWITCH]  │  │  [STEAM VALVE]│ │
│  │  ○───────────●───   │  │   [OFF/ON]      │  │  ○──────●──── │ │
│  │  ├─────────────┤    │  │                 │  │               │ │
│  │  0%         100%    │  │  [ECCS RESERVE] │  │  [POWER OUT]  │ │
│  │                     │  │   ██████░░ 60%  │  │    ___●___    │ │
│  │                     │  │                 │  │   /       \   │ │
│  │                     │  │                 │  │  | 227 MWe|   │ │
│  │                     │  │                 │  │   \_______/   │ │
│  └─────────────────────┘  └─────────────────┘  └───────────────┘ │
│                                                                  │
├──────────────────────────────────────────────────────────────────┤
│                                                                  │
│  [GRID DEMAND]  [DEMAND MET ●]              [  SCRAM BUTTON  ]   │
│   ___●___           (LED)                   [    (large red) ]   │
│  /       \                                  [                ]   │
│ | 500 MWe|                                  [                ]   │
│  \_______/                                                       │
│                      [RESET]                                     │
└──────────────────────────────────────────────────────────────────┘
```

**Visual Style:**

- Beige/grey panel background (#D0D0C0)
- Black panel dividers and section labels
- White gauge faces with black markings
- Red needles on all gauges
- LED indicator lights (green/yellow/red 10px circles)
- Grey buttons with shadows (4px offset)
- Large red SCRAM button (80×80px)

---

## Audio Design (If Implementing 3.1)

### Interaction Sounds

- **Slider movement:** Soft sliding friction sound
- **Button press:** Mechanical click
- **Switch toggle:** Sharp snap
- **SCRAM activation:** Heavy clunk + alarm blast

### Ambient Sounds

- **Reactor hum:** Low frequency drone (pitch = 50 + power/10)
- **Pump motor:** Medium whir (pitch = 100 + pump_speed)
- **Turbine spin:** High whine (pitch = 200 + rpm/10)

### Alert Sounds

- **Yellow warning:** Single beep every 2 seconds
- **Red danger:** Rapid beeping (3 per second)
- **Grid demand change:** Pleasant two-tone chime
- **Event notification:** Urgent triple beep

---

## Realistic 3-Week Timeline

### Week 1: Core Mechanics (Target: 16-18 marks)

**Days 1-2:** Project setup, Raylib window, basic rectangles for UI layout  
**Days 3-4:** Control rod slider working, affects power variable, draw simple gauges  
**Days 5-6:** Temperature physics complete, coolant pump working, needles animate  
**Day 7:** SCRAM button, timer, win/loss conditions, basic playable loop

**Milestone 1 Demo Features:**

- Working control rod slider
- Temperature and power gauges updating in real-time
- Basic heat transfer physics
- SCRAM button shuts down reactor
- Timer displays correctly
- Win/loss screens

**Expected Marks by Milestone 1:** 12-14 marks (most of Basic requirements)

---

### Week 2: Complete Systems (Target: 32-36 marks)

**Days 8-9:** Steam valve, turbine RPM, electrical output, pressure gauge  
**Days 10-11:** Grid demand system with meter and indicator, revenue counter  
**Days 12-13:** Warning lights system, ECCS implementation  
**Day 14:** Random event core system (2.9) with notification banner and 2 events

**Milestone 2 Demo Features:**

- All gauges functional (7 total)
- Grid demand changing with visual indicator
- Revenue accumulating
- ECCS system working
- Random events triggering (2 types working)
- Event notification banner displaying
- Complete playable game loop

**Expected Marks by Milestone 2:** 30-34 marks (all Basic + most Intermediate)

---

### Week 3: Events, Polish & Advanced (Target: 40-48 marks)

**Days 15-16:** Complete remaining 4 random events (2.10, 2.11)  
**Days 17-18:** Choose and implement 1-2 advanced features (prioritize sound or tutorial)  
**Days 19-20:** Bug fixing, balance tuning (event difficulty, timing), visual polish  
**Day 21:** Final testing, documentation, backup plan ready

**Final Demo Features:**

- All 6 random events working and tested
- All intermediate requirements complete
- 1-2 advanced features (sound pack OR tutorial OR enhanced physics)
- Polished UI with smooth animations
- Balanced and playable

**Expected Final Marks:** 40-46 marks

---

## Path to 38+ Marks

### Conservative Path (38-40 marks)

- ✅ All 14 Basic Requirements = **14 marks**
- ✅ 10 of 11 Intermediate (can skip one event set if needed) = **20 marks**
- ✅ 1 Advanced feature (sound OR tutorial) = **3-4 marks**
- **Total: 37-38 marks + 2 proposal = 39-40 marks**

### Recommended Path (42-46 marks)

- ✅ All 14 Basic Requirements = **14 marks**
- ✅ All 11 Intermediate Requirements = **22 marks**
- ✅ 2 Advanced features (e.g., sound + stats) = **6 marks**
- **Total: 42 marks + 2 proposal = 44 marks**

### Ambitious Path (46-50 marks)

- ✅ All 14 Basic Requirements = **14 marks**
- ✅ All 11 Intermediate Requirements = **22 marks**
- ✅ 3-4 Advanced features = **10-14 marks**
- **Total: 46-50 marks + 2 proposal = 48-52 marks**

### Feature Priority Order

1. **Week 1 focus:** Basic requirements 1.4-1.14 (core simulation + timer)
2. **Week 2 focus:** Intermediate 2.1-2.8 (all systems except events)
3. **Early Week 3:** Intermediate 2.9-2.11 (event system complete)
4. **Late Week 3:** Best 1-2 advanced features based on time

---

## Technical Notes

### Data Structures

```cpp
struct ReactorCore {
    float temperature;      // Celsius
    float power_output;     // MW thermal
    float control_rods;     // 0-100%
};

struct CoolantSystem {
    float pressure;         // MPa
    float pump_speed;       // 0-100%
    bool relief_valve_open;
    bool eccs_active;
    float eccs_reserve;     // 0-100%
};

struct TurbineGenerator {
    float rpm;              // Rotations per minute
    float steam_valve;      // 0-100%
    float electrical_output;// MW electrical
};

struct GridSystem {
    float target_power;     // MW electrical
    float demand_timer;     // Seconds until next change
    bool meeting_demand;
    float revenue;          // Dollars
};

struct RandomEvent {
    int event_id;           // 0-5 for event types
    float duration;         // Seconds remaining
    bool active;
    float next_event_timer; // Seconds until next event
};

enum EventType {
    EVENT_PUMP_DEGRADATION = 0,
    EVENT_GRID_FLUCTUATION = 1,
    EVENT_ROD_SLUGGISH = 2,
    EVENT_VALVE_STUCK = 3,
    EVENT_TEMP_SENSOR_MALFUNCTION = 4,
    EVENT_PRESSURE_SPIKE = 5
};
```

### Raylib Implementation Tips

- Use `DrawCircleSector()` for gauge arcs
- Use `DrawLineEx()` for gauge needles with rotation
- Use `DrawRectangleRounded()` for modern button aesthetics
- Use `CheckCollisionPointRec()` for slider/button mouse detection
- Use `GetMousePosition()` and `IsMouseButtonDown()` for drag interactions

---

## References

- Images of analog control panels for various purposes
- [Raylib documentation](https://www.raylib.com)
- [Candu Reactor statistics](https://www.xylenepower.com/CANDU%20Reactors.htm)

---

**Total Available Marks:** 50 marks exactly (14 + 22 + 14)  
**Realistic 3-Week Target:** 40-44 marks  
**With Proposal Bonus:** 42-46 marks total

---
**IMPORTANT**
**void DrawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color);**  