# Microsoft Windows Diagnostics Tools – Reverse Engineering Notes

## Overview

This project documents a complete reverse engineering of the Microsoft Windows Diagnostics Tools (MSDT) binary.
MSDT is a Windows component used for troubleshooting and diagnostics. It has been historically leveraged in exploitation scenarios (e.g., Follina CVE-2022-30190).

The reversing process involved analyzing the executable’s internal structures, regex filters, function flow, and object management routines to understand how commands are parsed, validated, and executed.
Goals

    Decompile MSDT’s main binary into a readable and annotated form.

    Identify and rename obfuscated function names (e.g., FUN_14001f4d4 → InitializeMatchContext).

    Map internal APIs like:

        Regex validation & bypass possibilities.

        Match buffer initialization (InitMatchBufferWithCharFlag).

        Expression evaluation and invocation handling.

    Understand escape handling and numeric parsing in regex quantifiers.

    Document potential bypass techniques for command execution filters.

## Key Findings

    Regex Filters: MSDT uses a PowerShell-oriented regex to block dangerous commands (invoke-expression, invoke-command, $([iex]), etc.). These filters can be bypassed using alternative invocation methods.

    Command Execution Path: Internally, MSDT constructs scriptblocks and executes them if they pass validation. C:\Windows\diagnostics

    Object Lifecycle: Reference counting and cleanup routines manage AST nodes and match buffers.

    Parser Logic: Implements quantifier parsing (*, +, {m,n}), with escape handling and validation.

## Tools Used

    Ghidra – For decompilation, symbol renaming, and control flow analysis.

    x64dbg/WinDbg – Runtime behavior tracing.

    PowerShell – For regex bypass testing.

# Disclaimer

This research is intended for educational purposes only.
Do not use this information for malicious activity.
Reversing Windows components may violate EULAs; proceed at your own discretion.
