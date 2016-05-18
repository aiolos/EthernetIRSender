<?php
/**
 * IR Commands translator
 */

$hexCommands = array();

$hexCommands[] = array(
    "description" => "Power ON/OFF",
    "command" => "A51C",
    "hexcommand" => "0000 0068 0000 0022 0168 00B4 0016 0043 0016 0016 0016 0043 0016 0016 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 0043 0016 0016 0016 0043 0016 0016 0016 0016 0016 0016 0016 0043 0016 0043 0016 0043 0016 0016 0016 0016 0016 0016 0016 0043 0016 0043 0016 0016 0016 0016 0016 0016 0016 0043 0016 0043 0016 0043 0016 03DD",
);
$hexCommands[] = array(
    "description" => "Power ON",
    "command" => "A51A",
    "hexcommand" => "0000 0068 0000 0022 0168 00B4 0016 0043 0016 0016 0016 0043 0016 0016 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 0043 0016 0016 0016 0043 0016 0016 0016 0016 0016 0043 0016 0016 0016 0043 0016 0043 0016 0016 0016 0016 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0016 0016 0043 0016 0043 0016 0043 0016 03DD",
);
$hexCommands[] = array(
    "description" => "Power OFF",
    "command" => "A51B",
    "hexcommand" => "0000 0068 0000 0022 0168 00B4 0016 0043 0016 0016 0016 0043 0016 0016 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 0043 0016 0016 0016 0043 0016 0043 0016 0016 0016 0016 0016 0016 0016 0016 0016 0016 0016 0043 0016 0016 0016 0016 0016 0043 0016 0043 0016 0043 0016 03DD",
);
$hexCommands[] = array(
    "description" => "Mute ON/OFF",
    "command" => "A512",
    "hexcommand" => "0000 0068 0000 0022 0168 00B4 0016 0043 0016 0016 0016 0043 0016 0016 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 0043 0016 0016 0016 0043 0016 0016 0016 0016 0016 0043 0016 0016 0016 0016 0016 0043 0016 0016 0016 0016 0016 0016 0016 0043 0016 0016 0016 0043 0016 0043 0016 0016 0016 0043 0016 0043 0016 0043 0016 03DD",
);
$hexCommands[] = array(
    "description" => "Mute ON",
    "command" => "A551",
    "hexcommand" => "0000 0068 0000 0022 0168 00B4 0016 0043 0016 0016 0016 0043 0016 0016 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0016 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0016 0016 0043 0016 0043 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 03DD",
);
$hexCommands[] = array(
    "description" => "Mute OFF",
    "command" => "A552",
    "hexcommand" => "0000 0068 0000 0022 0168 00B4 0016 0043 0016 0016 0016 0043 0016 0016 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 0043 0016 0016 0016 0043 0016 0016 0016 0016 0016 0043 0016 0016 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 03DD",
);
$hexCommands[] = array(
    "description" => "Volume Up",
    "command" => "A50A",
    "hexcommand" => "0000 0068 0000 0022 0168 00B4 0016 0043 0016 0016 0016 0043 0016 0016 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 0043 0016 0016 0016 0043 0016 0016 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0016 0016 0016 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 0043 0016 0043 0016 0043 0016 03DD",
);
$hexCommands[] = array(
    "description" => "Volume Down",
    "command" => "A50B",
    "hexcommand" => "0000 0068 0000 0022 0168 00B4 0016 0043 0016 0016 0016 0043 0016 0016 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 0043 0016 0016 0016 0043 0016 0016 0016 0043 0016 0043 0016 0016 0016 0043 0016 0016 0016 0016 0016 0016 0016 0016 0016 0016 0016 0016 0016 0043 0016 0016 0016 0043 0016 0043 0016 0043 0016 0043 0016 03DD",
);

foreach ($hexCommands as $hexcommand) {
    $hexcommandArray = explode(" ", $hexcommand["hexcommand"]);
    for ($i = 0; $i < 4; $i++) {
        array_shift($hexcommandArray);
    }

    $decArray = array();
    foreach($hexcommandArray as $element) {
        $decArray[] = hexdec($element) * 25;
    }
    echo $hexcommand["description"] . " - " . $hexcommand["command"] . PHP_EOL;
    echo implode(",", $decArray);
    echo PHP_EOL;
    echo PHP_EOL;
}



