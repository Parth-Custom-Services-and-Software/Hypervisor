#include <stdio.h>
#include <Hypervisor/Hypervisor.h>

int main(int argc, char* argv[]) {
    hv_vm_config_t vm_config = hv_vm_config_create(); // creates a VM config object (ios, iPadOS, etc etc) - void ptr
    hv_return_t vm_instance = hv_vm_create(vm_config); // Should be HV_SUCCESS if successful

    if (vm_config == NULL) {
        printf("VMConfig returned null, error with entitlements");
    }
    if (vm_instance != HV_SUCCESS) {
        printf("Error found when creating VM instance using hv_vm_create(). Error is: %d", vm_instance);
    }

    os_release(vm_config); // releases the memory stored by the vm_config
    hv_vm_destroy(); // destroys the vm associated with this process
}
