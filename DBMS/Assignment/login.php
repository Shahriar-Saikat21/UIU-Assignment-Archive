<?php
    include('connection.php');

    if(isset($_POST['login'])){
        $email = htmlspecialchars($_POST['email']);
        $password =htmlspecialchars($_POST['password']);

        $sql = "SELECT * FROM `member` WHERE email = '$email' AND _password = '$password'";
        $result = mysqli_query($conn,$sql);

        $users = mysqli_fetch_all($result,MYSQLI_ASSOC);

        if(empty($users)){
            echo "Login unsuccessful";
            exit();
        }else{
            header("Location:dashboard.php");
            exit();
        }

        mysqli_free_result($result);
    }

    mysqli_close($conn);
?>