#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_zigbee_core.h"
#include "esp_zigbee_zcl_command.h"
#include "zboss_api.h"

#define TAG "ZB_RELAY_ROUTER"

// GPIOs asignados a los relés (lógica activa baja)
#define RELAY1_GPIO GPIO_NUM_4
#define RELAY2_GPIO GPIO_NUM_5
#define RELAY3_GPIO GPIO_NUM_6
#define RELAY4_GPIO GPIO_NUM_7

static void configure_gpio_output(gpio_num_t gpio)
{
    gpio_config_t io_conf = {
        .pin_bit_mask = 1ULL << gpio,
        .mode = GPIO_MODE_OUTPUT,
        .pull_down_en = 0,
        .pull_up_en = 0,
        .intr_type = GPIO_INTR_DISABLE};
    gpio_config(&io_conf);
    gpio_set_level(gpio, 1); // Estado inicial: apagado (lógica baja activa)
}

void app_main(void)
{
    ESP_LOGI(TAG, "Iniciando zb_esp32c6_4reles_router");

    // Configurar GPIOs de los relés
    configure_gpio_output(RELAY1_GPIO);
    configure_gpio_output(RELAY2_GPIO);
    configure_gpio_output(RELAY3_GPIO);
    configure_gpio_output(RELAY4_GPIO);

    // Inicialización de Zigbee (simplificada para el ejemplo)
    ESP_LOGI(TAG, "Inicializando stack Zigbee (simulado)");
    // Aquí iría el código real del SDK para iniciar como Router Zigbee con 4 clústeres On/Off

    while (true)
    {
        // Simulación de estado periódico
        ESP_LOGI(TAG, "Relés activos: %d %d %d %d",
                 gpio_get_level(RELAY1_GPIO) == 0,
                 gpio_get_level(RELAY2_GPIO) == 0,
                 gpio_get_level(RELAY3_GPIO) == 0,
                 gpio_get_level(RELAY4_GPIO) == 0);

        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}
