 void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
if (n == 0)
    return;

bool row = false;
bool col = false;

// Check if the first row contains a zero
for (int j = 0; j < m; j++) {
    if (matrix[0][j] == 0) {
        row = true;
        break;
    }
}

// Check if the first column contains a zero
for (int i = 0; i < n; i++) {
    if (matrix[i][0] == 0) {
        col = true;
        break;
    }
}

// Use the first row and first column to mark zeros
for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
        if (matrix[i][j] == 0) {
            matrix[i][0] = 0;
            matrix[0][j] = 0;
        }
    }
}

// Set the elements to zero based on the markers
for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
            matrix[i][j] = 0;
        }
    }
}

// Set the first row to zero if needed
if (row) {
    for (int j = 0; j < m; j++) {
        matrix[0][j] = 0;
    }
}

// Set the first column to zero if needed
if (col) {
    for (int i = 0; i < n; i++) {
        matrix[i][0] = 0;
    }
}

    }
