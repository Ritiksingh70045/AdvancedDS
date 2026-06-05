// Shared variables
bool flag[2] = {false, false};
int turn;

// Process P0
do
{
  flag[0] = true; // P0 wants to enter CS
  turn = 1;       // Give chance to P1

  while (flag[1] && turn == 1)
    ; // Busy wait

  // Critical Section

  flag[0] = false; // Exit CS

  // Remainder Section

} while (true);

// Process P1
do
{
  flag[1] = true; // P1 wants to enter CS
  turn = 0;       // Give chance to P0

  while (flag[0] && turn == 0)
    ; // Busy wait

  // Critical Section

  flag[1] = false; // Exit CS

  // Remainder Section

} while (true);