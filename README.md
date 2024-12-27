<div align="center">
  <a href="https://github.com/mpeyre-s/42_minitalk"><img src="https://github.com/mpeyre-s/42_project_badges/raw/main/badges/minitalk.svg"/></a>
  <p>The aim of this project is to create a simple data exchange program between a client and a server using UNIX signals.</p>
  <br>
</div>

This project provided a practical introduction to low-level communication in UNIX systems, reinforcing concepts such as signals, processes, and bitwise manipulation.

# ➡️ Competencies Acquired

- **Signal Handling**: Gained proficiency in using UNIX signals (`SIGUSR1`, `SIGUSR2`) to establish communication between processes.

- **Inter-Process Communication (IPC)**: Developed an understanding of IPC mechanisms, particularly how to implement asynchronous messaging.

- **Bitwise Operations**: Acquired knowledge of bitwise operations to encode and decode messages for signal-based communication.

- **Real-Time Programming**: Improved skills in handling asynchronous events and ensuring data integrity in a non-linear execution flow.

- **Process Management**: Learned to manage processes, including process identification (PID) and the use of system calls like `kill` and `getpid`.

- **Error Handling**: Strengthened ability to handle errors and edge cases, ensuring the reliability and robustness of the client-server interaction.

# ➡️ Program Features

1. **Client and Server**:  
   - The server runs as a standalone process, waiting to receive messages from clients.  
   - The client sends messages (strings) to the server, which are displayed on the server's side.  

2. **Communication via Signals**:  
   - Communication is established using `SIGUSR1` and `SIGUSR2`.  
   - Each character is sent as a series of bits, encoded and transmitted one bit at a time.  

3. **Message Encoding and Decoding**:  
   - Messages are converted into binary representations by the client.  
   - The server decodes the received signals and reconstructs the original message.  

4. **Error Management**:  
   - Handles invalid PIDs, signal loss, and other potential communication issues.  


