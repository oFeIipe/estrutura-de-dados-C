typedef struct float_vector FloatVector;

FloatVector *create(int capacity);
void destroy(FloatVector **vector);
int size(const FloatVector *vector);
int capacity(const FloatVector *vector);
float at(const FloatVector *vector, int index);
float get(const FloatVector *vector, int index);
void append(FloatVector *vector, float value);
void set(FloatVector *vector, int index, float value);
void shift(FloatVector *vector);
void pop(FloatVector *vector);
void reverse(FloatVector *vector);
void unshift(FloatVector *vector, float value);
void remove_at_index(FloatVector *vector, int index);
void print(const FloatVector *vector);