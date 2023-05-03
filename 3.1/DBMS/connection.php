<?php
    $conn = mysqli_connect('localhost','root','','assignment');

    if(!$conn){
        echo "Connection Error". mysqli_connect_error();
    }
?>