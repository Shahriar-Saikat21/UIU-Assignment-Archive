<?php
    include('connection.php');

    if(isset($_POST['submit'])){
        $name = htmlspecialchars($_POST['name']);
        $email = htmlspecialchars($_POST['email']);
        $password =htmlspecialchars($_POST['password']);

        $sql = "INSERT INTO `member` VALUES ('$name','$email','$password')";
        $result = mysqli_query($conn,$sql);

        if($result){
            header("Location:index.html");
            exit();
        }else{
            echo "Connection Error". mysqli_connect_error();
        }
    }
    mysqli_close($conn);
?>