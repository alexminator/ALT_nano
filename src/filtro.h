
float movingAverage(float value)
{
  const byte nvalues = 8;  // Moving average window size
  static byte current = 0; // Index for current value
  static byte cvalues = 0; // Count of values read (<= nvalues)
  static float sum = 0;    // Rolling sum
  static float values[nvalues];

  sum += value;

  // If the window is full, adjust the sum by deleting the oldest value
  if (cvalues == nvalues)
    sum -= values[current];

  values[current] = value; // Replace the oldest with the latest

  if (++current >= nvalues)
    current = 0;

  if (cvalues < nvalues)
    cvalues += 1;

  return sum / cvalues;
}

