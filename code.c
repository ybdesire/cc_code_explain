unsigned int dword_404000 = 0x5A827999;
char byte_404004 = 0x1F;
int dword_404008 = 0;
char unk_40400C[16] = {0x31,0x41,0x59,0x26,0x53,0x58,0x97,0x93,0x23,0x84,0x62,0x64,0x33,0x83,0x27,0x95};

int __cdecl sub_401000(int a1, char *a2, int a3)
{
  int v3; // ebx
  int v4; // esi
  char v5; // al
  int v6; // edx
  unsigned __int8 v7; // cl
  int i; // [esp+14h] [ebp-14h]
  unsigned __int8 v9; // [esp+18h] [ebp-10h]
  char v10[16]; // [esp+20h] [ebp-8h] BYREF

  v3 = a1;
  v4 = 0;
  memset(v10, 0, sizeof(v10));
  
  if (a3 > 0x10)
  {
LABEL_2:
    v9 = 0;
    goto LABEL_5;
  }
  else
  {
    v9 = a3;
  }

LABEL_5:
  for (i = 0; i < v9; ++i)
  {
    v5 = a2[i] ^ byte_404004;
    v6 = (dword_404000 >> (i % 24)) & 0xFF;
    v7 = v5 + v6 - 0x20;
    v10[i] = v7 ^ unk_40400C[i % 16];
    
    if (v10[i] > 0x7F)
    {
      dword_404008 = 1;
    }
    else
    {
      dword_404008 = 0;
    }
    
    v4 += v10[i] * (i + 1);
  }

  if (v4 == 0x12345678)
  {
    v3 = 1;
  }
  else
  {
    v3 = 0;
  }
  
  return v3;
}

int __cdecl main(int argc, const char **argv, const char **envp)
{
  int v3; // eax
  char *v4; // esi
  int v5; // ebx
  int result; // eax

  if (argc < 2)
  {
    printf("Usage: %s <serial>\n", argv[0]);
    return 1;
  }
  
  v4 = (char *)argv[1];
  v5 = strlen(v4);
  v3 = sub_401000(0, v4, v5);
  
  if (v3)
  {
    printf("Valid serial!\n");
    result = 0;
  }
  else
  {
    printf("Invalid serial!\n");
    result = -1;
  }
  
  return result;
}
