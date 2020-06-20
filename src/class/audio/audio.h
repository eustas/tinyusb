/* 
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Ha Thach (tinyusb.org)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * This file is part of the TinyUSB stack.
 */

/** \ingroup group_class
 *  \defgroup ClassDriver_Audio Audio
 *            Currently only MIDI subclass is supported
 *  @{ */

#ifndef _TUSB_AUDIO_H__
#define _TUSB_AUDIO_H__

#include "common/tusb_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/// Isochronous End Point Attributes
typedef enum
{
	TUSB_ISO_EP_ATT_ASYNCHRONOUS 	= 0x04,
	TUSB_ISO_EP_ATT_ADAPTIVE 		= 0x08,
	TUSB_ISO_EP_ATT_SYNCHRONOUS 	= 0x0C,
	TUSB_ISO_EP_ATT_DATA 			= 0x00,	///< Data End Point
	TUSB_ISO_EP_ATT_FB 				= 0x20, ///< Feedback End Point
} tusb_iso_ep_attribute_t;

/// Audio Interface Subclass Codes
typedef enum
{
	AUDIO_SUBCLASS_UNDEFINED = 0x00,
	AUDIO_SUBCLASS_CONTROL 		   , ///< Audio Control
	AUDIO_SUBCLASS_STREAMING       , ///< Audio Streaming
	AUDIO_SUBCLASS_MIDI_STREAMING  , ///< MIDI Streaming
} audio_subclass_type_t;

/// Audio Function Subclass Codes
typedef enum
{
	AUDIO_FUNCTION_SUBCLASS_UNDEFINED = 0x00,
} audio_function_subclass_type_t;

/// Audio Protocol Codes
typedef enum
{
	AUDIO_PROTOCOL_V1                   = 0x00, ///< Version 1.0
	AUDIO_PROTOCOL_V2                   = 0x20, ///< Version 2.0
	AUDIO_PROTOCOL_V3                   = 0x30, ///< Version 3.0
} audio_protocol_type_t;

/// Audio Function Category Codes
typedef enum
{
	AUDIO_FUNC_DESKTOP_SPEAKER    = 0x01,
	AUDIO_FUNC_HOME_THEATER       = 0x02,
	AUDIO_FUNC_MICROPHONE         = 0x03,
	AUDIO_FUNC_HEADSET            = 0x04,
	AUDIO_FUNC_TELEPHONE          = 0x05,
	AUDIO_FUNC_CONVERTER          = 0x06,
	AUDIO_FUNC_SOUND_RECODER      = 0x07,
	AUDIO_FUNC_IO_BOX             = 0x08,
	AUDIO_FUNC_MUSICAL_INSTRUMENT = 0x09,
	AUDIO_FUNC_PRO_AUDIO          = 0x0A,
	AUDIO_FUNC_AUDIO_VIDEO        = 0x0B,
	AUDIO_FUNC_CONTROL_PANEL      = 0x0C,
} audio_function_t;

/// Audio Class-Specific AC Interface Descriptor Subtypes UAC2
typedef enum
{
	AUDIO_CS_AC_INTERFACE_AC_DESCRIPTOR_UNDEF   = 0x00,
	AUDIO_CS_AC_INTERFACE_HEADER                = 0x01,
	AUDIO_CS_AC_INTERFACE_INPUT_TERMINAL        = 0x02,
	AUDIO_CS_AC_INTERFACE_OUTPUT_TERMINAL       = 0x03,
	AUDIO_CS_AC_INTERFACE_MIXER_UNIT            = 0x04,
	AUDIO_CS_AC_INTERFACE_SELECTOR_UNIT         = 0x05,
	AUDIO_CS_AC_INTERFACE_FEATURE_UNIT          = 0x06,
	AUDIO_CS_AC_INTERFACE_EFFECT_UNIT           = 0x07,
	AUDIO_CS_AC_INTERFACE_PROCESSING_UNIT       = 0x08,
	AUDIO_CS_AC_INTERFACE_EXTENSION_UNIT        = 0x09,
	AUDIO_CS_AC_INTERFACE_CLOCK_SOURCE          = 0x0A,
	AUDIO_CS_AC_INTERFACE_CLOCK_SELECTOR        = 0x0B,
	AUDIO_CS_AC_INTERFACE_CLOCK_MULTIPLIER      = 0x0C,
	AUDIO_CS_AC_INTERFACE_SAMPLE_RATE_CONVERTER = 0x0D,
} audio_cs_ac_interface_subtype_t;

/// Audio Class-Specific AS Interface Descriptor Subtypes UAC2
typedef enum
{
	AUDIO_CS_AS_INTERFACE_AS_DESCRIPTOR_UNDEF 	= 0x00,
	AUDIO_CS_AS_INTERFACE_AS_GENERAL            = 0x01,
	AUDIO_CS_AS_INTERFACE_FORMAT_TYPE        	= 0x02,
	AUDIO_CS_AS_INTERFACE_ENCODER       		= 0x03,
	AUDIO_CS_AS_INTERFACE_DECODER       		= 0x04,
} audio_cs_as_interface_subtype_t;

/// Audio Class-Control Values UAC2
typedef enum
{
	AUDIO_CTRL_NONE		= 0x00, 		///< No Host access
	AUDIO_CTRL_R 		= 0x01, 		///< Host read access only
	AUDIO_CTRL_RW 		= 0x03, 		///< Host read write access
} audio_control_t;

/// Audio Class-Specific AC Interface Descriptor Controls UAC2
typedef enum
{
	AUDIO_CS_AS_INTERFACE_CTRL_LATENCY_POS 	= 0,
} audio_cs_ac_interface_control_pos_t;

/// Audio Class-Specific AS Interface Descriptor Controls UAC2
typedef enum
{
	AUDIO_CS_AS_INTERFACE_CTRL_ACTIVE_ALT_SET_POS 	= 0,
	AUDIO_CS_AS_INTERFACE_CTRL_VALID_ALT_SET_POS	= 2,
} audio_cs_as_interface_control_pos_t;

/// Audio Class-Specific EP Descriptor Subtypes UAC2
typedef enum
{
	AUDIO_CS_EP_SUBTYPE_DESCRIPTOR_UNDEFINED 	= 0x00,
	AUDIO_CS_EP_SUBTYPE_GENERAL 				= 0x01,
} audio_cs_ep_subtype_t;

/// Audio Class-Specific AS Isochronous Data EP Attributes UAC2
typedef enum
{
	AUDIO_CS_AS_ISO_DATA_EP_ATT_MAX_PACKETS_ONLY 	= 0x80,
	AUDIO_CS_AS_ISO_DATA_EP_ATT_NON_MAX_PACKETS_OK 	= 0x00,
} audio_cs_as_iso_data_ep_attribute_t;

/// Audio Class-Specific AS Isochronous Data EP Controls UAC2
typedef enum
{
	AUDIO_CS_AS_ISO_DATA_EP_CTRL_PITCH_POS 			= 0,
	AUDIO_CS_AS_ISO_DATA_EP_CTRL_DATA_OVERRUN_POS 	= 2,
	AUDIO_CS_AS_ISO_DATA_EP_CTRL_DATA_UNDERRUN_POS 	= 4,
} audio_cs_as_iso_data_ep_control_pos_t;

/// Audio Class-Specific AS Isochronous Data EP Lock Delay Units UAC2
typedef enum
{
	AUDIO_CS_AS_ISO_DATA_EP_LOCK_DELAY_UNIT_UNDEFINED 		= 0x00,
	AUDIO_CS_AS_ISO_DATA_EP_LOCK_DELAY_UNIT_MILLISEC 		= 0x01,
	AUDIO_CS_AS_ISO_DATA_EP_LOCK_DELAY_UNIT_PCM_SAMPLES 	= 0x02,
} audio_cs_as_iso_data_ep_lock_delay_unit_t;

/// Audio Class-Clock Source Attributes UAC2
typedef enum
{
	AUDIO_CLOCK_SOURCE_ATT_EXT_CLK 		= 0x00,
	AUDIO_CLOCK_SOURCE_ATT_INT_FIX_CLK 	= 0x01,
	AUDIO_CLOCK_SOURCE_ATT_INT_VAR_CLK 	= 0x02,
	AUDIO_CLOCK_SOURCE_ATT_INT_PRO_CLK 	= 0x03,
	AUDIO_CLOCK_SOURCE_ATT_CLK_SYC_SOF 	= 0x04,
} audio_clock_source_attribute_t;

/// Audio Class-Clock Source Controls UAC2
typedef enum
{
	AUDIO_CLOCK_SOURCE_CTRL_CLK_FRQ_POS 	= 0,
	AUDIO_CLOCK_SOURCE_CTRL_CLK_VAL_POS 	= 2,
} audio_clock_source_control_pos_t;

/// Audio Class-Clock Selector Controls UAC2
typedef enum
{
	AUDIO_CLOCK_SELECTOR_CTRL_POS 	= 0,
} audio_clock_selector_control_pos_t;

/// Audio Class-Clock Multiplier Controls UAC2
typedef enum
{
	AUDIO_CLOCK_MULTIPLIER_CTRL_NUMERATOR_POS 		= 0,
	AUDIO_CLOCK_MULTIPLIER_CTRL_DENOMINATOR_POS 	= 2,
} audio_clock_multiplier_control_pos_t;

/// Audio Class-Terminal Types UAC2
typedef enum
{
	AUDIO_TERM_TYPE_USB_UNDEFINED 		= 0x0100,
	AUDIO_TERM_TYPE_USB_STREAMING 		= 0x0101,
	AUDIO_TERM_TYPE_USB_VENDOR_SPEC		= 0x01FF,
} audio_terminal_type_t;

/// Audio Class-Input Terminal Types UAC2
typedef enum
{
	AUDIO_TERM_TYPE_IN_UNDEFINED 		= 0x0200,
	AUDIO_TERM_TYPE_IN_GENERIC_MIC 		= 0x0201,
	AUDIO_TERM_TYPE_IN_DESKTOP_MIC 		= 0x0202,
	AUDIO_TERM_TYPE_IN_PERSONAL_MIC 	= 0x0203,
	AUDIO_TERM_TYPE_IN_OMNI_MIC 		= 0x0204,
	AUDIO_TERM_TYPE_IN_ARRAY_MIC 		= 0x0205,
	AUDIO_TERM_TYPE_IN_PROC_ARRAY_MIC 	= 0x0206,
} audio_terminal_input_type_t;

/// Audio Class-Input Terminal Controls UAC2
typedef enum
{
	AUDIO_IN_TERM_CTRL_CPY_PROT_POS 	= 0,
	AUDIO_IN_TERM_CTRL_CONNECTOR_POS 	= 2,
	AUDIO_IN_TERM_CTRL_OVERLOAD_POS 	= 4,
	AUDIO_IN_TERM_CTRL_CLUSTER_POS 		= 6,
	AUDIO_IN_TERM_CTRL_UNDERFLOW_POS 	= 8,
	AUDIO_IN_TERM_CTRL_OVERFLOW_POS 	= 10,
} audio_terminal_input_control_pos_t;

/// Audio Class-Output Terminal Types UAC2
typedef enum
{
	AUDIO_TERM_TYPE_OUT_UNDEFINED 				= 0x0300,
	AUDIO_TERM_TYPE_OUT_GENERIC_SPEAKER 		= 0x0301,
	AUDIO_TERM_TYPE_OUT_HEADPHONES 				= 0x0302,
	AUDIO_TERM_TYPE_OUT_HEAD_MNT_DISP_AUIDO 	= 0x0303,
	AUDIO_TERM_TYPE_OUT_DESKTOP_SPEAKER 		= 0x0304,
	AUDIO_TERM_TYPE_OUT_ROOM_SPEAKER	 		= 0x0305,
	AUDIO_TERM_TYPE_OUT_COMMUNICATION_SPEAKER 	= 0x0306,
	AUDIO_TERM_TYPE_OUT_LOW_FRQ_EFFECTS_SPEAKER = 0x0307,
} audio_terminal_output_type_t;

/// Audio Class-Output Terminal Controls UAC2
typedef enum
{
	AUDIO_OUT_TERM_CTRL_CPY_PROT_POS 	= 0,
	AUDIO_OUT_TERM_CTRL_CONNECTOR_POS 	= 2,
	AUDIO_OUT_TERM_CTRL_OVERLOAD_POS 	= 4,
	AUDIO_OUT_TERM_CTRL_UNDERFLOW_POS 	= 6,
	AUDIO_OUT_TERM_CTRL_OVERFLOW_POS 	= 8,
} audio_terminal_output_control_pos_t;

/// Audio Class-Feature Unit Controls UAC2
typedef enum
{
	AUDIO_FEATURE_UNIT_CTRL_MUTE_POS 			= 0,
	AUDIO_FEATURE_UNIT_CTRL_VOLUME_POS 			= 2,
	AUDIO_FEATURE_UNIT_CTRL_BASS_POS 			= 4,
	AUDIO_FEATURE_UNIT_CTRL_MID_POS 			= 6,
	AUDIO_FEATURE_UNIT_CTRL_TREBLE_POS 			= 8,
	AUDIO_FEATURE_UNIT_CTRL_GRAPHIC_EQU_POS 	= 10,
	AUDIO_FEATURE_UNIT_CTRL_AGC_POS 			= 12,
	AUDIO_FEATURE_UNIT_CTRL_DELAY_POS 			= 14,
	AUDIO_FEATURE_UNIT_CTRL_BASS_BOOST_POS 		= 16,
	AUDIO_FEATURE_UNIT_CTRL_LOUDNESS_POS		= 18,
	AUDIO_FEATURE_UNIT_CTRL_INPUT_GAIN_POS		= 20,
	AUDIO_FEATURE_UNIT_CTRL_INPUT_GAIN_PAD_POS	= 22,
	AUDIO_FEATURE_UNIT_CTRL_PHASE_INV_POS		= 24,
	AUDIO_FEATURE_UNIT_CTRL_UNDERFLOW_POS		= 26,
	AUDIO_FEATURE_UNIT_CTRL_OVERFLOW_POS		= 28,
} audio_feature_unit_control_pos_t;

/// Audio Class-Format Type Codes UAC2
typedef enum
{
	AUDIO_FORMAT_TYPE_UNDEFINED 	= 0x00,
	AUDIO_FORMAT_TYPE_I 			= 0x01,
	AUDIO_FORMAT_TYPE_II 			= 0x02,
	AUDIO_FORMAT_TYPE_III 			= 0x03,
	AUDIO_FORMAT_TYPE_IV 			= 0x04,
	AUDIO_EXT_FORMAT_TYPE_I 		= 0x81,
	AUDIO_EXT_FORMAT_TYPE_II 		= 0x82,
	AUDIO_EXT_FORMAT_TYPE_III 		= 0x83,
} audio_format_type_t;

/// Audio Class-Audio Data Format Type I UAC2
typedef enum
{
	AUDIO_DATA_FORMAT_TYPE_I_PCM 			= 0x00000000,
	AUDIO_DATA_FORMAT_TYPE_I_PCM8 			= 0x00000001,
	AUDIO_DATA_FORMAT_TYPE_I_IEEE_FLOAT 	= 0x00000002,
	AUDIO_DATA_FORMAT_TYPE_I_ALAW 			= 0x00000003,
	AUDIO_DATA_FORMAT_TYPE_I_MULAW 			= 0x00000004,
} audio_data_format_type_I_t;

/// Audio Class-Audio Channel Configuration UAC2
typedef enum
{
	AUDIO_CHANNEL_CONFIG_NON_PREDEFINED 			= 0x00000000,
	AUDIO_CHANNEL_CONFIG_FRONT_LEFT 				= 0x00000001,
	AUDIO_CHANNEL_CONFIG_FRONT_RIGHT 				= 0x00000002,
	AUDIO_CHANNEL_CONFIG_FRONT_CENTER 				= 0x00000004,
	AUDIO_CHANNEL_CONFIG_LOW_FRQ_EFFECTS 			= 0x00000008,
	AUDIO_CHANNEL_CONFIG_BACK_LEFT 					= 0x00000010,
	AUDIO_CHANNEL_CONFIG_BACK_RIGHT 				= 0x00000020,
	AUDIO_CHANNEL_CONFIG_FRONT_LEFT_OF_CENTER 		= 0x00000040,
	AUDIO_CHANNEL_CONFIG_FRONT_RIGHT_OF_CENTER 		= 0x00000080,
	AUDIO_CHANNEL_CONFIG_BACK_CENTER 				= 0x00000100,
	AUDIO_CHANNEL_CONFIG_SIDE_LEFT 					= 0x00000200,
	AUDIO_CHANNEL_CONFIG_SIDE_RIGHT 				= 0x00000400,
	AUDIO_CHANNEL_CONFIG_TOP_CENTER 				= 0x00000800,
	AUDIO_CHANNEL_CONFIG_TOP_FRONT_LEFT				= 0x00001000,
	AUDIO_CHANNEL_CONFIG_TOP_FRONT_CENTER			= 0x00002000,
	AUDIO_CHANNEL_CONFIG_TOP_FRONT_RIGHT			= 0x00004000,
	AUDIO_CHANNEL_CONFIG_TOP_BACK_LEFT 				= 0x00008000,
	AUDIO_CHANNEL_CONFIG_TOP_BACK_CENTER			= 0x00010000,
	AUDIO_CHANNEL_CONFIG_TOP_BACK_RIGHT				= 0x00020000,
	AUDIO_CHANNEL_CONFIG_TOP_FRONT_LEFT_OF_CENTER	= 0x00040000,
	AUDIO_CHANNEL_CONFIG_TOP_FRONT_RIGHT_OF_CENTER	= 0x00080000,
	AUDIO_CHANNEL_CONFIG_LEFT_LOW_FRQ_EFFECTS		= 0x00100000,
	AUDIO_CHANNEL_CONFIG_RIGHT_LOW_FRQ_EFFECTS		= 0x00200000,
	AUDIO_CHANNEL_CONFIG_TOP_SIDE_LEFT				= 0x00400000,
	AUDIO_CHANNEL_CONFIG_TOP_SIDE_RIGHT				= 0x00800000,
	AUDIO_CHANNEL_CONFIG_BOTTOM_CENTER				= 0x01000000,
	AUDIO_CHANNEL_CONFIG_BACK_LEFT_OF_CENTER		= 0x02000000,
	AUDIO_CHANNEL_CONFIG_BACK_RIGHT_OF_CENTER		= 0x04000000,
	AUDIO_CHANNEL_CONFIG_RAW_DATA					= 0x80000000,
} audio_channel_config_t;

/// AUDIO Class-Specific AC Interface Header Descriptor (4.7.2)
typedef struct TU_ATTR_PACKED
{
  uint8_t bLength            ; ///< Size of this descriptor in bytes: 9.
  uint8_t bDescriptorType    ; ///< Descriptor Type. Value: TUSB_DESC_CS_INTERFACE.
  uint8_t bDescriptorSubType ; ///< Descriptor SubType. Value: AUDIO_CS_AC_INTERFACE_HEADER.
  uint16_t bcdADC            ; ///< Audio Device Class Specification Release Number in Binary-Coded Decimal. Value: U16_TO_U8S_LE(0x0200).
  uint8_t bCategory 		 ; ///< Constant, indicating the primary use of this audio function, as intended by the manufacturer. See: audio_function_t.
  uint16_t wTotalLength      ; ///< Total number of bytes returned for the class-specific AudioControl interface descriptor. Includes the combined length of this descriptor header and all Clock Source, Unit and Terminal descriptors.
  uint8_t bmControls 		 ; ///< See: audio_cs_ac_interface_control_pos_t.
} audio_desc_cs_ac_interface_t;

/// AUDIO Clock Source Descriptor (4.7.2.1)
typedef struct TU_ATTR_PACKED
{
  uint8_t bLength            ; ///< Size of this descriptor in bytes: 8.
  uint8_t bDescriptorType    ; ///< Descriptor Type. Value: TUSB_DESC_CS_INTERFACE.
  uint8_t bDescriptorSubType ; ///< Descriptor SubType. Value: AUDIO_CS_AC_INTERFACE_CLOCK_SOURCE.
  uint8_t bClockID 		 	 ; ///< Constant uniquely identifying the Clock Source Entity within the audio function. This value is used in all requests to address this Entity.
  uint8_t bmAttributes 		 ; ///< See: audio_clock_source_attribute_t.
  uint8_t bmControls 		 ; ///< See: audio_clock_source_control_pos_t.
  uint8_t bAssocTerminal	 ; ///< Terminal ID of the Terminal that is associated with this Clock Source.
  uint8_t iClockSource	 	 ; ///< Index of a string descriptor, describing the Clock Source Entity.
} audio_desc_clock_source_t;

/// AUDIO Clock Selector Descriptor (4.7.2.2) for ONE pin
typedef struct TU_ATTR_PACKED
{
  uint8_t bLength            ; ///< Size of this descriptor, in bytes: 7+p.
  uint8_t bDescriptorType    ; ///< Descriptor Type. Value: TUSB_DESC_CS_INTERFACE.
  uint8_t bDescriptorSubType ; ///< Descriptor SubType. Value: AUDIO_CS_AC_INTERFACE_CLOCK_SELECTOR.
  uint8_t bClockID 		 	 ; ///< Constant uniquely identifying the Clock Selector Entity within the audio function. This value is used in all requests to address this Entity.
  uint8_t bNrInPins 		 ; ///< Number of Input Pins of this Unit: p = 1 thus bNrInPins = 1.
  uint8_t baCSourceID 		 ; ///< ID of the Clock Entity to which the first Clock Input Pin of this Clock Selector Entity is connected..
  uint8_t bmControls 		 ; ///< See: audio_clock_selector_control_pos_t.
  uint8_t iClockSource	 	 ; ///< Index of a string descriptor, describing the Clock Selector Entity.
} audio_desc_clock_selector_t;

/// AUDIO Clock Selector Descriptor (4.7.2.2) for multiple pins
#define audio_desc_clock_selector_n_t(source_num) \
  struct TU_ATTR_PACKED {         \
	uint8_t bLength            	; \
	uint8_t bDescriptorType    	; \
	uint8_t bDescriptorSubType 	; \
	uint8_t bClockID 		 	; \
	uint8_t bNrInPins 		 	; \
    struct TU_ATTR_PACKED {    	  \
        uint8_t baSourceID		; \
    } sourceID[source_num]		; \
    uint8_t bmControls			; \
    uint8_t iClockSource		; \
 }

/// AUDIO Clock Multiplier Descriptor (4.7.2.3)
typedef struct TU_ATTR_PACKED
{
  uint8_t bLength            ; ///< Size of this descriptor, in bytes: 7.
  uint8_t bDescriptorType    ; ///< Descriptor Type. Value: TUSB_DESC_CS_INTERFACE.
  uint8_t bDescriptorSubType ; ///< Descriptor SubType. Value: AUDIO_CS_AC_INTERFACE_CLOCK_MULTIPLIER.
  uint8_t bClockID 		 	 ; ///< Constant uniquely identifying the Clock Multiplier Entity within the audio function. This value is used in all requests to address this Entity.
  uint8_t bCSourceID 		 ; ///< ID of the Clock Entity to which the last Clock Input Pin of this Clock Selector Entity is connected.
  uint8_t bmControls 		 ; ///< See: audio_clock_multiplier_control_pos_t.
  uint8_t iClockSource	 	 ; ///< Index of a string descriptor, describing the Clock Multiplier Entity.
} audio_desc_clock_multiplier_t;

/// AUDIO Input Terminal Descriptor(4.7.2.4)
typedef struct TU_ATTR_PACKED
{
  uint8_t bLength            ; ///< Size of this descriptor, in bytes: 17.
  uint8_t bDescriptorType    ; ///< Descriptor Type. Value: TUSB_DESC_CS_INTERFACE.
  uint8_t bDescriptorSubType ; ///< Descriptor SubType. Value: AUDIO_CS_AC_INTERFACE_INPUT_TERMINAL.
  uint16_t wTerminalType 	 ; ///< Constant characterizing the type of Terminal. See: audio_terminal_type_t for USB streaming and audio_terminal_input_type_t for other input types.
  uint8_t bAssocTerminal	 ; ///< ID of the Output Terminal to which this Input Terminal is associated.
  uint8_t bCSourceID 		 ; ///< ID of the Clock Entity to which this Input Terminal is connected.
  uint8_t bNrChannels	 	 ; ///< Number of logical output channels in the Terminal’s output audio channel cluster.
  uint32_t bmChannelConfig	 ; ///< Describes the spatial location of the logical channels. See:audio_channel_config_t.
  uint16_t bmControls	 	 ; ///< See: audio_terminal_input_control_pos_t.
  uint8_t iTerminal	 	 	 ; ///< Index of a string descriptor, describing the Input Terminal.
} audio_desc_input_terminal_t;

/// AUDIO Output Terminal Descriptor(4.7.2.5)
typedef struct TU_ATTR_PACKED
{
  uint8_t bLength            ; ///< Size of this descriptor, in bytes: 12.
  uint8_t bDescriptorType    ; ///< Descriptor Type. Value: TUSB_DESC_CS_INTERFACE.
  uint8_t bDescriptorSubType ; ///< Descriptor SubType. Value: AUDIO_CS_AC_INTERFACE_OUTPUT_TERMINAL.
  uint8_t bTerminalID 	 	 ; ///< Constant uniquely identifying the Terminal within the audio function. This value is used in all requests to address this Terminal.
  uint16_t wTerminalType	 ; ///< Constant characterizing the type of Terminal. See: audio_terminal_type_t for USB streaming and audio_terminal_output_type_t for other output types.
  uint8_t bAssocTerminal 	 ; ///< Constant, identifying the Input Terminal to which this Output Terminal is associated.
  uint8_t bSourceID		 	 ; ///< ID of the Unit or Terminal to which this Terminal is connected.
  uint8_t bCSourceID	 	 ; ///< ID of the Clock Entity to which this Output Terminal is connected.
  uint16_t bmControls	 	 ; ///< See: audio_terminal_output_type_t.
  uint8_t iTerminal	 	 	 ; ///< Index of a string descriptor, describing the Output Terminal.
} audio_desc_output_terminal_t;

/// AUDIO Feature Unit Descriptor(4.7.2.8) for ONE channel
typedef struct TU_ATTR_PACKED
{
  uint8_t bLength            ; ///< Size of this descriptor, in bytes: 14.
  uint8_t bDescriptorType    ; ///< Descriptor Type. Value: TUSB_DESC_CS_INTERFACE.
  uint8_t bDescriptorSubType ; ///< Descriptor SubType. Value: AUDIO_CS_AC_INTERFACE_FEATURE_UNIT.
  uint8_t bUnitID    	 	 ; ///< Constant uniquely identifying the Unit within the audio function. This value is used in all requests to address this Unit.
  uint8_t bSourceID	 		 ; ///< ID of the Unit or Terminal to which this Feature Unit is connected.
  struct TU_ATTR_PACKED {
	  uint32_t bmaControls	 ; ///< See: audio_feature_unit_control_pos_t. Controls0 is master channel 0 (always present) and Controls1 is logical channel 1.
  } controls[2] 		     ;
  uint8_t iTerminal	 	 	 ; ///< Index of a string descriptor, describing this Feature Unit.
} audio_desc_feature_unit_t;

/// AUDIO Feature Unit Descriptor(4.7.2.8) for multiple channels
#define audio_desc_feature_unit_n_t(ch_num) \
  struct TU_ATTR_PACKED {         \
	uint8_t bLength            	; /* 6+(ch_num+1)*4 */\
	uint8_t bDescriptorType    	; \
	uint8_t bDescriptorSubType 	; \
	uint8_t bUnitID 		 	; \
	uint8_t bSourceID 		 	; \
    struct TU_ATTR_PACKED {    	  \
        uint32_t bmaControls	; \
    } controls[ch_num+1]		; \
    uint8_t iTerminal			; \
 }

/// AUDIO Class-Specific AS Interface Descriptor(4.9.2)
typedef struct TU_ATTR_PACKED
{
  uint8_t bLength            ; ///< Size of this descriptor, in bytes: 16.
  uint8_t bDescriptorType    ; ///< Descriptor Type. Value: TUSB_DESC_CS_INTERFACE.
  uint8_t bDescriptorSubType ; ///< Descriptor SubType. Value: AUDIO_CS_AS_INTERFACE_AS_GENERAL.
  uint8_t bTerminalLink	 	 ; ///< The Terminal ID of the Terminal to which this interface is connected.
  uint8_t bmControls	 	 ; ///< See: audio_cs_as_interface_control_pos_t.
  uint8_t bFormatType 	 	 ; ///< Constant identifying the Format Type the AudioStreaming interface is using. See: audio_format_type_t.
  uint32_t bmFormats	 	 ; ///< The Audio Data Format(s) that can be used to communicate with this interface.See: audio_data_format_type_I_t.
  uint8_t bNrChannels	 	 ; ///< Number of physical channels in the AS Interface audio channel cluster.
  uint32_t bmChannelConfig	 ; ///< Describes the spatial location of the physical channels. See: audio_channel_config_t.
  uint8_t iChannelNames	 	 ; ///< Index of a string descriptor, describing the name of the first physical channel.
} audio_desc_cs_as_interface_t;

/// AUDIO Type I Format Type Descriptor(2.3.1.6 - Audio Formats)
typedef struct TU_ATTR_PACKED
{
  uint8_t bLength            ; ///< Size of this descriptor, in bytes: 6.
  uint8_t bDescriptorType    ; ///< Descriptor Type. Value: TUSB_DESC_CS_INTERFACE.
  uint8_t bDescriptorSubType ; ///< Descriptor SubType. Value: AUDIO_CS_AS_INTERFACE_FORMAT_TYPE.
  uint8_t bFormatType	 	 ; ///< Constant identifying the Format Type the AudioStreaming interface is using. Value: AUDIO_FORMAT_TYPE_I.
  uint8_t bSubslotSize	 	 ; ///< The number of bytes occupied by one audio subslot. Can be 1, 2, 3 or 4.
  uint8_t bBitResolution 	 ; ///< The number of effectively used bits from the available bits in an audio subslot.
} audio_desc_type_I_format_t;

/// AUDIO Class-Specific AS Isochronous Audio Data Endpoint Descriptor(4.10.1.2)
typedef struct TU_ATTR_PACKED
{
  uint8_t bLength            ; ///< Size of this descriptor, in bytes: 8.
  uint8_t bDescriptorType    ; ///< Descriptor Type. Value: TUSB_DESC_CS_ENDPOINT.
  uint8_t bDescriptorSubType ; ///< Descriptor SubType. Value: AUDIO_CS_EP_SUBTYPE_GENERAL.
  uint8_t bmAttributes	 	 ; ///< See: audio_cs_as_iso_data_ep_attribute_t.
  uint8_t bmControls	 	 ; ///< See: audio_cs_as_iso_data_ep_control_pos_t.
  uint8_t bLockDelayUnits 	 ; ///< Indicates the units used for the wLockDelay field. See: audio_cs_as_iso_data_ep_lock_delay_unit_t.
  uint16_t wLockDelay 		 ; ///< Indicates the time it takes this endpoint to reliably lock its internal clock recovery circuitry. Units used depend on the value of the bLockDelayUnits field.
} audio_desc_cs_as_iso_data_ep_t;


/** @} */

#ifdef __cplusplus
}
#endif

#endif

/** @} */
