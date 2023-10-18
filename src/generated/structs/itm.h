/**
 * \file
 * \brief Generated by ifgen (3.1.7).
 */
#pragma once

#include "../ifgen/common.h"
#include "ItmStimulusPort.h"

namespace ARM
{

/**
 * Instrumentation Trace Macrocell Unit
 */
struct [[gnu::packed]] itm
{
    /* Constant attributes. */
    static constexpr std::size_t size = 4096; /*!< itm's size in bytes. */

    /* Fields. */
    static constexpr std::size_t STIM_length = 256;
    ItmStimulusPort STIM[STIM_length];
    static constexpr std::size_t reserved_padding0_length = 640;
    const uint32_t reserved_padding0[reserved_padding0_length] = {};
    static constexpr std::size_t TER_length = 8;
    uint32_t TER[TER_length];
    static constexpr std::size_t reserved_padding1_length = 8;
    const uint32_t reserved_padding1[reserved_padding1_length] = {};
    uint32_t TPR; /*!< (Cortex-M4) Enables an operating system to control the
stimulus ports that are accessible by user code. */
    static constexpr std::size_t reserved_padding2_length = 15;
    const uint32_t reserved_padding2[reserved_padding2_length] = {};
    uint32_t TCR;
    static constexpr std::size_t reserved_padding3_length = 83;
    const uint32_t reserved_padding3[reserved_padding3_length] = {};
    uint32_t PID4;
    uint32_t PID5;
    uint32_t PID6;
    uint32_t PID7;
    uint32_t PID0;
    uint32_t PID1;
    uint32_t PID2;
    uint32_t PID3;
    uint32_t CID0;
    uint32_t CID1;
    uint32_t CID2;
    uint32_t CID3;

    /* Methods. */

    /**
     * Get TER's STIMENA field.
     *
     * Enable or disable stimulus port (32x + n).
     */
    inline uint32_t get_TER_STIMENA(std::size_t index) volatile
    {
        return (TER[index] >> 0u) & 0b11111111111111111111111111111111u;
    }

    /**
     * Set TER's STIMENA field.
     *
     * Enable or disable stimulus port (32x + n).
     */
    inline void set_TER_STIMENA(std::size_t index, uint32_t value) volatile
    {
        uint32_t curr = TER[index];

        curr &= ~(0b11111111111111111111111111111111u << 0u);
        curr |= (value & 0b11111111111111111111111111111111u) << 0u;

        TER[index] = curr;
    }

    /**
     * Get TPR's PRIVMASK field.
     *
     * Bit mask to enable tracing on ITM stimulus ports.
     */
    inline uint32_t get_TPR_PRIVMASK() volatile
    {
        return (TPR >> 0u) & 0b11111111111111111111111111111111u;
    }

    /**
     * Set TPR's PRIVMASK field.
     *
     * Bit mask to enable tracing on ITM stimulus ports.
     */
    inline void set_TPR_PRIVMASK(uint32_t value) volatile
    {
        uint32_t curr = TPR;

        curr &= ~(0b11111111111111111111111111111111u << 0u);
        curr |= (value & 0b11111111111111111111111111111111u) << 0u;

        TPR = curr;
    }

    /**
     * Get TCR's BUSY bit.
     *
     * Whether or not the ITM is currently processing events.
     */
    inline bool get_TCR_BUSY() volatile
    {
        return TCR & (1u << 23u);
    }

    /**
     * Get TCR's TraceBusID field.
     *
     * Identifier for multi-source trace stream formatting.
     */
    inline uint8_t get_TCR_TraceBusID() volatile
    {
        return (TCR >> 16u) & 0b111111u;
    }

    /**
     * Set TCR's TraceBusID field.
     *
     * Identifier for multi-source trace stream formatting.
     */
    inline void set_TCR_TraceBusID(uint8_t value) volatile
    {
        uint32_t curr = TCR;

        curr &= ~(0b111111u << 16u);
        curr |= (value & 0b111111u) << 16u;

        TCR = curr;
    }

    /**
     * Get TCR's GTSFREQ field.
     *
     * Global timestamp frequency.
     */
    inline uint8_t get_TCR_GTSFREQ() volatile
    {
        return (TCR >> 10u) & 0b11u;
    }

    /**
     * Set TCR's GTSFREQ field.
     *
     * Global timestamp frequency.
     */
    inline void set_TCR_GTSFREQ(uint8_t value) volatile
    {
        uint32_t curr = TCR;

        curr &= ~(0b11u << 10u);
        curr |= (value & 0b11u) << 10u;

        TCR = curr;
    }

    /**
     * Get TCR's TSPrescale field.
     *
     * Local timestamp prescaler.
     */
    inline uint8_t get_TCR_TSPrescale() volatile
    {
        return (TCR >> 8u) & 0b11u;
    }

    /**
     * Set TCR's TSPrescale field.
     *
     * Local timestamp prescaler.
     */
    inline void set_TCR_TSPrescale(uint8_t value) volatile
    {
        uint32_t curr = TCR;

        curr &= ~(0b11u << 8u);
        curr |= (value & 0b11u) << 8u;

        TCR = curr;
    }

    /**
     * Get TCR's SWOENA bit.
     *
     * Enables asynchronous clocking of the timestamp counter.
     */
    inline bool get_TCR_SWOENA() volatile
    {
        return TCR & (1u << 4u);
    }

    /**
     * Set TCR's SWOENA bit.
     *
     * Enables asynchronous clocking of the timestamp counter.
     */
    inline void set_TCR_SWOENA() volatile
    {
        TCR |= 1u << 4u;
    }

    /**
     * Clear TCR's SWOENA bit.
     *
     * Enables asynchronous clocking of the timestamp counter.
     */
    inline void clear_TCR_SWOENA() volatile
    {
        TCR &= ~(1u << 4u);
    }

    /**
     * Toggle TCR's SWOENA bit.
     *
     * Enables asynchronous clocking of the timestamp counter.
     */
    inline void toggle_TCR_SWOENA() volatile
    {
        TCR ^= 1u << 4u;
    }

    /**
     * Get TCR's TXENA bit.
     *
     * Enables forwarding of hardware event packet from the DWT unit to
     * the ITM for output to TPIU.
     */
    inline bool get_TCR_TXENA() volatile
    {
        return TCR & (1u << 3u);
    }

    /**
     * Set TCR's TXENA bit.
     *
     * Enables forwarding of hardware event packet from the DWT unit to
     * the ITM for output to TPIU.
     */
    inline void set_TCR_TXENA() volatile
    {
        TCR |= 1u << 3u;
    }

    /**
     * Clear TCR's TXENA bit.
     *
     * Enables forwarding of hardware event packet from the DWT unit to
     * the ITM for output to TPIU.
     */
    inline void clear_TCR_TXENA() volatile
    {
        TCR &= ~(1u << 3u);
    }

    /**
     * Toggle TCR's TXENA bit.
     *
     * Enables forwarding of hardware event packet from the DWT unit to
     * the ITM for output to TPIU.
     */
    inline void toggle_TCR_TXENA() volatile
    {
        TCR ^= 1u << 3u;
    }

    /**
     * Get TCR's SYNCENA bit.
     *
     * Enables Synchronization packet transmission for a synchronous
     * TPIU.
     */
    inline bool get_TCR_SYNCENA() volatile
    {
        return TCR & (1u << 2u);
    }

    /**
     * Set TCR's SYNCENA bit.
     *
     * Enables Synchronization packet transmission for a synchronous
     * TPIU.
     */
    inline void set_TCR_SYNCENA() volatile
    {
        TCR |= 1u << 2u;
    }

    /**
     * Clear TCR's SYNCENA bit.
     *
     * Enables Synchronization packet transmission for a synchronous
     * TPIU.
     */
    inline void clear_TCR_SYNCENA() volatile
    {
        TCR &= ~(1u << 2u);
    }

    /**
     * Toggle TCR's SYNCENA bit.
     *
     * Enables Synchronization packet transmission for a synchronous
     * TPIU.
     */
    inline void toggle_TCR_SYNCENA() volatile
    {
        TCR ^= 1u << 2u;
    }

    /**
     * Get TCR's TSENA bit.
     *
     * Enables Local timestamp generation.
     */
    inline bool get_TCR_TSENA() volatile
    {
        return TCR & (1u << 1u);
    }

    /**
     * Set TCR's TSENA bit.
     *
     * Enables Local timestamp generation.
     */
    inline void set_TCR_TSENA() volatile
    {
        TCR |= 1u << 1u;
    }

    /**
     * Clear TCR's TSENA bit.
     *
     * Enables Local timestamp generation.
     */
    inline void clear_TCR_TSENA() volatile
    {
        TCR &= ~(1u << 1u);
    }

    /**
     * Toggle TCR's TSENA bit.
     *
     * Enables Local timestamp generation.
     */
    inline void toggle_TCR_TSENA() volatile
    {
        TCR ^= 1u << 1u;
    }

    /**
     * Get TCR's ITMENA bit.
     *
     * This is the enable control for the ITM unit.
     */
    inline bool get_TCR_ITMENA() volatile
    {
        return TCR & (1u << 0u);
    }

    /**
     * Set TCR's ITMENA bit.
     *
     * This is the enable control for the ITM unit.
     */
    inline void set_TCR_ITMENA() volatile
    {
        TCR |= 1u << 0u;
    }

    /**
     * Clear TCR's ITMENA bit.
     *
     * This is the enable control for the ITM unit.
     */
    inline void clear_TCR_ITMENA() volatile
    {
        TCR &= ~(1u << 0u);
    }

    /**
     * Toggle TCR's ITMENA bit.
     *
     * This is the enable control for the ITM unit.
     */
    inline void toggle_TCR_ITMENA() volatile
    {
        TCR ^= 1u << 0u;
    }

    /**
     * Get all of TCR's bit fields.
     */
    inline void get_TCR(bool &BUSY, uint8_t &TraceBusID, uint8_t &GTSFREQ,
                        uint8_t &TSPrescale, bool &SWOENA, bool &TXENA,
                        bool &SYNCENA, bool &TSENA, bool &ITMENA) volatile
    {
        uint32_t curr = TCR;

        BUSY = curr & (1u << 23u);
        TraceBusID = (curr >> 16u) & 0b111111u;
        GTSFREQ = (curr >> 10u) & 0b11u;
        TSPrescale = (curr >> 8u) & 0b11u;
        SWOENA = curr & (1u << 4u);
        TXENA = curr & (1u << 3u);
        SYNCENA = curr & (1u << 2u);
        TSENA = curr & (1u << 1u);
        ITMENA = curr & (1u << 0u);
    }

    /**
     * Set all of TCR's bit fields.
     */
    inline void set_TCR(uint8_t TraceBusID, uint8_t GTSFREQ,
                        uint8_t TSPrescale, bool SWOENA, bool TXENA,
                        bool SYNCENA, bool TSENA, bool ITMENA) volatile
    {
        uint32_t curr = TCR;

        curr &= ~(0b111111u << 16u);
        curr |= (TraceBusID & 0b111111u) << 16u;
        curr &= ~(0b11u << 10u);
        curr |= (GTSFREQ & 0b11u) << 10u;
        curr &= ~(0b11u << 8u);
        curr |= (TSPrescale & 0b11u) << 8u;
        curr &= ~(0b1u << 4u);
        curr |= (SWOENA & 0b1u) << 4u;
        curr &= ~(0b1u << 3u);
        curr |= (TXENA & 0b1u) << 3u;
        curr &= ~(0b1u << 2u);
        curr |= (SYNCENA & 0b1u) << 2u;
        curr &= ~(0b1u << 1u);
        curr |= (TSENA & 0b1u) << 1u;
        curr &= ~(0b1u << 0u);
        curr |= (ITMENA & 0b1u) << 0u;

        TCR = curr;
    }
};

static_assert(sizeof(itm) == itm::size);

static volatile itm *const ITM = reinterpret_cast<itm *>(0xE0000000);

}; // namespace ARM
