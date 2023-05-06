void initializeSD()
{
  pinMode(CS_PIN, OUTPUT);
  
  if (SD.begin())
  {
    Serial.println("SD available");
    delay(1000);
  } else
  {
    Serial.println("SD Unavailable");
    return;
  }
  
    
}

int openFileToWrite(char *filename)
{
  mylogger = SD.open(filename, FILE_WRITE);
  if (mylogger)
  {
    return 1;
  } else
  {
    Serial.println("Unable to open file");
    return 0;
  }
}

int writeToFile(String text, int fileend = 0)
{
  int res = 1;
  if (mylogger && fileend)
  {
    mylogger.println(text);
  } else if (mylogger)
  {
    mylogger.print(text);
    mylogger.print(',');
  } else
  {
    res = 0;
  }
  return res;
}

void closeFile()
{
  if (mylogger)
  {
    mylogger.close();
  }
}
