// API Function List C-Fundamentals

float map(float in, float inMin, float inMax, float outMin, float outMax) {
    float m, out, b;
    m = (outMax - outMin) / (inMax - inMin);
    b = outMin - m * inMin;
    out = m * in + b;
    return(out);
}

void setupRandArray(int n2, float x[], int min, int max) {
    for(int j = 0; j < n2; j++) {
        x[j] = min + rand() % (max - min +  1);
    }
}

void setupRandIntArray(int n2, int x[], int min, int max) {
    for(int j = 0; j < n2; j++) {
        x[j] = min + rand() % (max - min +  1);
    }
}

int negOne() {
    int n;
    n = pow(-1, rand());
    return(n);
}

void printRandArray(int n, int x[], char label[]) {
    printf("%s", label);
    for(int j = 0; j < n; j++) {
        printf("%-d ", x[j]);
    }
    printf("\n");
}

void printRandCharArray(int n, char x[], char label[]) {
    printf("%s", label);
    for(int j = 0; j < n; j++) {
        printf("%-c", x[j]);
    }
    printf("\n");
}

void printFloatArray(int n, float x[], char label[]) {
    printf("%s", label);
    for(int j = 0; j < n; j++) {
        printf("%-.2f ", x[j]);
    }
    printf("\n");
}

float getAve(int n, float x[]) {
    int aveSum = 0;
    float ave;
    for(int j = 0; j < n; j++) {
        aveSum = x[j] + aveSum;
    }
    ave = aveSum / n;

    return(ave);
}

float getStandDev(int n, float x[] ) {
    float standDev, ave, range;
    float sum = 0;
    float sum2 = 0;

    for(int j = 0; j < n; j++) sum = x[j] + sum;
    ave = sum / n;
    for(int j = 0; j < n; j++) {
        range = (x[j] - ave) * (x[j] - ave);
        sum2 = range + sum2;
    }
    standDev = sqrt((sum2/n));

    return(standDev);
}

float getMin(int n, float x[]) {
    float min = x[0];
    for(int j = 1; j < n; j++) {
        if(x[j] < min) min = x[j];
    }
    return(min);
}

float getMax(int n, float x[]) {
    float max;
    max = x[0];
    for(int j = 1; j < n; j++) {
        if(x[j] > max) max = x[j];
    }
    return(max);
}

float getRange(int n, float x[]) {
    float min = x[0];
    float max = x[0];
    float range;
    for(int j = 1; j < n; j++) {
        if(x[j] < min) min = x[j];
        if(x[j] > max) max = x[j];
    }

    range = max - min;
    return(range);
}

int getValuesinRange(int n, float x[], float out[], int min, int max) {
    int num = 0;
    for(int j = 0; j < n; j++) {
        if(x[j] <= max && x[j] >= min) {
            out[num] = x[j];
            num++;
        }
    }
    return(num);
}

int getIndexInRange(int n, float x[], int ind[], int min, int max) {
    int count = 0;
    for(int j = 0;  j < n; j++) {
        if(x[j] <= max && x[j] >= min) {
            ind[count] = j;
            count++;
        }
    }
    return(count);
}

void setUpRandSequence(int n, char x[]) {
    for(int j = 0; j < n; j++) {
        int mutation = rand() % 4;
        if(mutation == 0) x[j] = 'A';
        if(mutation == 1) x[j] = 'T';
        if(mutation == 2) x[j] = 'C';
        if(mutation == 3) x[j] = 'G';
    }
    x[n] = '\0';
}

int getBaseCount(char x[], char base) {
    int n = strlen(x);
    int count = 0;

    for(int j = 0; j < n; j++) if(x[j] == base) count++;
    return(count);
}

void getAllBaseCounts(char x[], float y[]) {
    int n = strlen(x);
    int a = 0;
    int g = 0;
    int c = 0;
    int t = 0;
    for(int j = 0; j < n; j++) {
        if(x[j] == 'A') a++;
        if(x[j] == 'G') g++;
        if(x[j] == 'C') c++;
        if(x[j] == 'T') t++;
    }

        y[0] = (float)a /n * 100;
        y[1] = (float)g/n * 100;
        y[2] = (float)c/n *100;
        y[3] = (float)t/n * 100;
}

void printStats(char x[], float y[]) {
    printf("\nSequence: %s\n", x);
    int n = strlen(x);
    printf("Length:%d\n", n);
    printf("Base Stats\nA:%.1f\nG:%.1f\nC:%.1f\nT:%.1f", y[0], y[1], y[2], y[3]);
}

void blankOut(char x[], char base, char y[]) {
    int n = strlen(x);
    for(int j = 0; j < n; j++) {
        if(x[j] != base) y[j] = '.';
        else y[j] = base;
    }
}

void displayAllBlankOut(char x[]) {
    int n = strlen(x);
    char y[n];
    printf("\nBase Sequence T:");
    for(int j = 0; j < n; j++) {
       if(x[j] != 'T') y[j] = '.';
       else y[j] = 'T';
       printf("%c", y[j]);
    }
    printf("\nBase Sequence A:");
    for(int j = 0; j < n; j++) {
       if(x[j] != 'A') y[j] = '.';
       else y[j] = 'A';
       printf("%c", y[j]);
    }
    printf("\nBase Sequence C:");
    for(int j = 0; j < n; j++) {
       if(x[j] != 'C') y[j] = '.';
       else y[j] = 'C';
       printf("%c", y[j]);
    }
    printf("\nBase Sequence G:");
    for(int j = 0; j < n; j++) {
       if(x[j] != 'G') y[j] = '.';
       else y[j] = 'G';
       printf("%c", y[j]);
    }
}

int myStrLen(char x[]) {
    int n = 0;
    int count2 = 1;
    while(count2 != 0) {
        if(x[n] != '\0') n++;
        else count2 = 0;
    }
    return(n);
}

void myStrCopy(char x[], char y[]) {
    int n = strlen(x);
    for(int j = 0; j < n; j++) {
        y[j] = x[j];
    }
}

void myStrCat(char x[], char y[]) {
    int i, j;
    for(i = 0; x[i] != '\0'; i++);
    for(j = 0; y[j] != '\0'; j++) {
        x[i +j] = y[j];
    }
    x[i + j] = '\0';
}

int getSubString(char x[], char y[], int startn, int length) {
    int n = strlen(x);
    int count = 0;
    int m = startn + length;
    for(int j = 0; j < n; j++) {
        if(j >= startn && j < m) {
            y[count] = x[j];
            count++;
        }
    }
    return(count);
}

void printASCIITable() {
    FILE *ASCII;
    ASCII = fopen("\\file-location\\out.text”, "w");

    int i, j, k;
    int count = 0;
    for(i = 0; i < 4; i++ ) fprintf(ASCII, "Decimal \t Hex \tChar\t");
    fprintf(ASCII, "\n");
    for(j = 0; j < 32; j++) {
       for(k = 0; k < 4; k++) {
           count = k*32 + j;
           fprintf(ASCII, " %d \t   \t %x\t", count, count);
           if(count > 31) fprintf(ASCII, " %c\t", count);
           if(count <= 31)fprintf(ASCII, "  \t");
       }
       fprintf(ASCII, "\n");
    }
    fclose(ASCII);
}}

int numUpperCase(char x[]) {
    int n = strlen(x);
    int m;
    int count = 0;
    for(int i = 0; i < n; i++) {
        m = x[i];
        if(m > 64 && m <= 90) count++;
    }
    return(count);
}

int numLowerCase(char x[]) {
    int n = strlen(x);
    int m;
    int count = 0;
    for(int i = 0; i < n; i++) {
        m = x[i];
        if(m > 96 && m <= 122) count++;
    }
    return(count);
}

void toUpperCase(char x[], char y[]) {
    int m;
    for(int i = 0; i < strlen(x); i++) {
        m = x[i];
        if(m > 96 && m <= 122) y[i] = m - 32;
        else y[i] = x[i];
    }
}

void toLowerCase(char x[], char y[]) {
    int m;
    for(int i = 0; i < strlen(x); i++) {
        m = x[i];
        if(m > 64 && m <= 90) y[i] = m + 32;
        else y[i] = x[i];
    }
}

int capWord(char x[]) {
    int count = 0;
    int m, count2, out[20];
    for(int j = 0; j < strlen(x); j++) {
		if(x[j] == ' ') {
			out[count] = j;
			count++;
		}
    }
    for(int i = 0; i < count; i++) {
        m = out[i] + 1;
        x[m] = x[m] - 32;
    }
    count++;
    return(count);
}

int wordStartInd(char x[], int out[]) {
    int count = 0;
    for(int i = 0; i < strlen(x); i++) {
        if(x[i] == ' ') {
            out[count] = i;
            count++;
        }
    }
    count++;
    return(count);
}

int testForPrime(int n) {
    int trueFalse = 1;
    for(int i = 2; i < n / 2; i++) {
        if((n % i) ==0) trueFalse = 0;
    }
    return(trueFalse);
}

void bitwiseAND(int n, int x[], int y[], int res[]) {
    for(int i = 0; i < n; i++) {
        if((x[i] * y[i]) != 0) res[i] = 1;
        else res[i] = 0;
    }
}

void bitwiseOR(int n, int x[], int y[], int res[]) {
    for(int i = 0; i < n; i++) {
        if((x[i]+y[i]) !=0)res[i] = 1;
        else res[i] = 0;
    }
}

void bitwiseXOR(int n, int x[], int y[], int res[]) {
    for(int i = 0; i < n; i++) {
        if((x[i]+y[i]) == 1)res[i] = 1;
        else res[i] = 0;
    }
}

int boolAdd(int n, int x[], int y[], int sum[]) {
    int carry = 0;
    int sum2 = 0;
    for(int i = 0;i < n; i++) {
      if (x[i] == 1) x[i] = pow(2, n - i - 1);
      else x[i] = 0;
      if(y[i] ==  1) y[i] = pow(2, n - i - 1);
      else y[i] == 0;
      sum2 = sum2 + x[i] + y[i];
    }
    if(sum2 >= pow(2, n)) carry++;
    for(int j = n-1; j >= 0; j--) {
        sum[j] = sum2 % 2;
        sum2 = sum2 / 2;
    }
              return(carry);
}

char dec2HexNib(int x) {
	char hex;
	
	if(x < 10) hex = x + 48;
	if(x > 10) hex = x + 55;

	return(hex);
}

int hex2DecNib(char x) {
	int dec;
	
	if(x < 58) dec = x - 48;
	if(x > 64) dec = x - 55;

	return(dec);
}

void hex2Bin(char x, int x[]) {
	int dec;
	
	if(x < 10) hex = x + 48;
	if(x > 10) hex = x + 55;

	for(int i = 3; i >= 0; i--) {
	 b[i] = dec % 2;
	 dec = dec / 2;
	}
}

char bin2Hex(int bin[]) {
   char hex;
   int sum = 0;
   int sum2 = 0;
   for(int i = 0; i <= 4; i++) {
       if(bin[i] == 1) sum2 = pow(2, 3 - i);
       else sum2 = 0;
       sum = sum + sum2;
   }
   if(sum < 10) hex = sum + 48;
   if(sum > 10) hex = sum + 55;

   return(hex);
}

void padBin(int n, int x[], int totalBits) {
   int sub = totalBits - n;
   int binAdd[totalBits];
   for(int i = 0; i < sub; i++) {
       binAdd[i + sub] = x[i];
       x[i] = 0;
   }
   for(int j = sub; j < totalBits; j++) x[j] = binAdd[j];
}

int unpadBin(int n, int x[]) {
   int count = 0;
   int i = 0;

   while(x[i] ==0) {
       count++;
       i++;
   }
   int temp[n - count];
   for(int j = 0; j < n - count; j++) temp[j] = x[count + j];
   for(int k = 0; k < n - count; k++)  x[k] = temp[k];
   return(count);
}

int bin2Dec(int n, int x[]) {
   int sum = 0;
   int sum2 = 0;
   for(int i = 0; i < n; i++) {
       if(x[i] == 1) sum2 = pow(2, (n - 1) - i);
       else sum2 = 0;
       sum = sum + sum2;
   }
   return(sum);
}

int dec2Bin(int dec, int x[]) {
   int count = 0;
   int i = 0;
       while(dec != 0) {
		   x[i] = dec % 2;
		   dec = dec / 2;
		   count++;
		   i++;
       }
   return(count);
}