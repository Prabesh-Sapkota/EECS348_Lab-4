#include <stdio.h>
#include <ctype.h>

// Conversion functions
float celsius_to_fahrenheit(float c) {
    return (c * 9.0f / 5.0f) + 32.0f;
}

float fahrenheit_to_celsius(float f) {
    return (f - 32.0f) * 5.0f / 9.0f;
}

float celsius_to_kelvin(float c) {
    return c + 273.15f;
}

float kelvin_to_celsius(float k) {
    return k - 273.15f;
}

float fahrenheit_to_kelvin(float f) {
    return celsius_to_kelvin(fahrenheit_to_celsius(f));
}

float kelvin_to_fahrenheit(float k) {
    return celsius_to_fahrenheit(kelvin_to_celsius(k));
}

// Function to normalize any scale to Celsius for easy categorization
float to_celsius(float temp, char scale) {
    switch (scale) {
        case 'C': return temp;
        case 'F': return fahrenheit_to_celsius(temp);
        case 'K': return kelvin_to_celsius(temp);
        default:  return temp;
    }
}

// Function to convert between any two supported scales
float convert_temperature(float temp, char from_scale, char to_scale) {
    if (from_scale == to_scale) {
        return temp;
    }
    
    if (from_scale == 'C' && to_scale == 'F') return celsius_to_fahrenheit(temp);
    if (from_scale == 'C' && to_scale == 'K') return celsius_to_kelvin(temp);
    if (from_scale == 'F' && to_scale == 'C') return fahrenheit_to_celsius(temp);
    if (from_scale == 'F' && to_scale == 'K') return fahrenheit_to_kelvin(temp);
    if (from_scale == 'K' && to_scale == 'C') return kelvin_to_celsius(temp);
    if (from_scale == 'K' && to_scale == 'F') return kelvin_to_fahrenheit(temp);

    return temp;
}

// Function to display category and advisory based on Celsius temperature
void categorize_and_advise(float celsius) {
    if (celsius < 0.0f) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Wear a heavy coat and bundle up!\n");
    } else if (celsius < 10.0f) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius < 25.0f) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: The weather is pleasant. Enjoy your day!\n");
    } else if (celsius < 35.0f) {
        printf("Temperature category:Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors and keep hydrated!\n");
    }
}

int main(void) {
    float input_temp, converted_temp;
    char from_scale, to_scale;

    // 1. Get input temperature value
    printf("Enter the temperature value: ");
    if (scanf("%f", &input_temp) != 1) {
        printf("Error: Invalid numeric input.\n");
        return 1;
    }

    // 2. Get original scale
    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &from_scale);
    from_scale = toupper(from_scale);

    if (from_scale != 'C' && from_scale != 'F' && from_scale != 'K') {
        printf("Error: Invalid scale '%c'. Please use C, F, or K.\n", from_scale);
        return 1;
    }

    // Check for physically impossible Kelvin temperatures
    if (from_scale == 'K' && input_temp < 0.0f) {
        printf("Error: Temperature in Kelvin cannot be negative (below absolute zero).\n");
        return 1;
    }

    // 3. Get target scale
    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &to_scale);
    to_scale = toupper(to_scale);

    if (to_scale != 'C' && to_scale != 'F' && to_scale != 'K') {
        printf("Error: Invalid scale '%c'. Please use C, F, or K.\n", to_scale);
        return 1;
    }

    // Perform conversion
    converted_temp = convert_temperature(input_temp, from_scale, to_scale);

    // Output results
    printf("Converted temperature: %.2f %c\n", converted_temp, to_scale);

    // Weather categorization uses the Celsius equivalent
    float celsius_equivalent = to_celsius(converted_temp, to_scale);
    categorize_and_advise(celsius_equivalent);

    return 0;
}
