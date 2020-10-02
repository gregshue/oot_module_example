/** @file
 *  @brief OMX Module Hello API
 */

/*
 * Copyright (c) 2020 Legrand North America, LLC.
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef OMX_INCLUDE_OMX_OMX_MODULE_HELLO_H_
#define OMX_INCLUDE_OMX_OMX_MODULE_HELLO_H_

/**
 * @brief OMX Module Hello
 * @defgroup omx_module_hello_apis Module Hello sAPIs
 * @{
 */

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Return the number of times module_hello said this power-up.
 *
 * @retval >= 0 If successful.
 * @retval Errno Negative errno code if failure.
 */
int32_t omx_module_hello_said(void);

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#endif /* OMX_INCLUDE_OMX_OMX_MODULE_HELLO_H_ */
