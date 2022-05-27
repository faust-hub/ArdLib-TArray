#include <Arduino.h>
#include <TArray.h>

template <typename T>
void printArray(TArray <T> array) {
	Serial.print("array length: ");
	Serial.println(array.length());

	array.forEach([](T val, uint8_t ind) -> void {
		Serial.print("[");
		Serial.print(ind);
		Serial.print("] ");
		Serial.println(val);
	});

	Serial.println();
}

void setup() {
	Serial.begin(9600);
	Serial.println();

	Serial.println("- init ------------------------------------");

	TArray <uint8_t> array;

	printArray(array);

	Serial.println("- .push/.pop/operator[] -------------------");

	array.push(23);
	array.push(17, 52, 77);
	array.push(38);
	array.push(66);

	array.pop();

	array[1] = 99;
	array[10] = 12;

	printArray(array);

	Serial.println("- .modify ---------------------------------");

	array.modify([](uint8_t val, uint8_t ind) -> uint8_t {
		return val + 100;
	});

	printArray(array);

	Serial.println("- .map ------------------------------------");

	TArray <float> arrayOther = array.map <float> ([](uint8_t val) -> float {
		return val + 0.25;
	});

	printArray(arrayOther);

	// ...
}

void loop() {
}