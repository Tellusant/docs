# Background for Internal Training Document

> Assume a humanoid robot. How should I describe the AI that runs it. I'm not interested in the human interface through LLM, but what operates the robot on the floor. I need this for an internal  training session.

To describe the AI that operates a humanoid robot, you need to look beyond conversational models (like LLMs) and focus on embodied AI, robotic control architectures, and cognitive-motor frameworks. 

Humanoid robots require a sophisticated stack because they operate in unstructured human environments, possess high degrees of freedom (DoF), and must balance physical laws with real-time decision-making. 

Here is a structured framework and breakdown you can use for your class, organized by the functional layers of the AI stack. 

## 1. The Core Concept: Embodied AI 

Instead of treating AI as a disembodied "brain" that only processes text or images, describe the system as Embodied AI. 

Definition: AI that is physically instantiated in an artificial body, capable of perceiving the world through sensors, reasoning about physical constraints, and acting upon the world through actuators. 

Key characteristic: It bridges the gap between high-level semantic reasoning (understanding what to do) and low-level continuous control (managing physics, torque, and balance at 500+ Hz). 

## 2. The Architectural Layers (How to Describe the Stack)

When writing about or presenting this for a class, it is best to break the software/AI architecture into three hierarchical tiers:

### 2.A The High-Level Layer: Cognitive & Task Planning
This layer handles abstract reasoning, goal decomposition, and long-horizon planning.  
	What it does: Breaks down a vague command (e.g., "Clean up the kitchen") into sequential tasks (walk to table → locate cup → grasp handle).  
	Technologies/Concepts: Vision-Language-Action (VLA) models, hierarchical task networks (HTNs), and behavior trees. (Note: While LLMs/VLMs might be used here for semantic understanding, they sit at the top of the stack and hand off instructions to lower-level controllers).  
  
### 2.B The Mid-Level Layer: Perception, State Estimation, & Navigation
This layer processes raw sensor data to build a real-time model of the robot's internal state and external environment.  
	What it does: Fuses data from LiDAR, depth cameras, and IMUs (Inertial Measurement Units) to answer: Where am I? What is around me? What is my joint configuration?  
	Technologies/Concepts: Simultaneous Localization and Mapping (SLAM), 3D computer vision, semantic segmentation, and Kalman filtering for state estimation.  
### 2.C The Low-Level Layer: Whole-Body Control & Locomotion
This is the critical layer that makes a humanoid robot distinct from a software agent or a wheeled robot. It deals directly with physics.  

	What it does: Manages dynamic balance, bipedal walking, joint torque calculations, and manipulation force feedback. It operates at very high frequencies (hundreds of cycles per second).  
  
- Technologies/Concepts:
  -	Model Predictive Control (MPC): Anticipates physical forces and predicts the robot's movement over a short time horizon to maintain balance.
  -	Reinforcement Learning (RL) for Locomotion: Policies trained in physics simulators (like Isaac Gym) and deployed to hardware to handle uneven terrain, pushes, and slips gracefully.
 


