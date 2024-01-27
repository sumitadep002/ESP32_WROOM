# ESP32 WROOM DevKit C Project

This repository contains the source code and setup script for an ESP32 WROOM DevKit C project. The included script, `Toolchain_SDK/script.sh`, is designed to download and install dependencies, IDF SDK, and set up the development environment.

## Getting Started

To get started with this ESP32 project, follow the steps below:

1. **Run the Setup Script:**

    ```bash
    cd Toolchain_SDK
    ./script.sh
    ```

    This script will download and install dependencies such as CMake, Make, Python, Git, and the ESP-IDF SDK. Run it in a directory where you want to store your ESP-related documents, projects, and other resources.

2. **Study Material:**

    Explore the `Study_Material` directory for datasheets, manuals, and other useful resources that will assist you on your ESP32 development journey.

3. **Starting a New Project:**

    To begin a new project, follow these steps:

    a. Go to the directory where you want to set up the new project.

    b. Run the following command:

    ```bash
    set-idf
    idf.py create-project project_name
    ```

    Replace `project_name` with the desired name for your new project.

## Usage

After the successful installation by running `script.sh`, you will find examples in `Toolchain_SDK/esp/esp-idf/examples`. These examples cover a wide range of topics, helping you understand peripherals and other aspects of ESP32 development.

## Additional Resources

For more in-depth information and documentation on ESP-IDF and ESP32 development, refer to the official documentation:

- [ESP-IDF Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/index.html)

## Contributing

If you encounter any issues or have suggestions for improvement, feel free to open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

**Note:** This is just the beginning, and more content will be added as the project progresses.

