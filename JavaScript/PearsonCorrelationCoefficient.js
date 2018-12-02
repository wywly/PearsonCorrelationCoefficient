function mean(data) {
    var sum = 0;
    for (let index = 0; index < data.length; index++) {
        sum += data[index];
    }
    return sum / data.length;
}

function var_(data) {
    var sum = 0;
    for (let index = 0; index < data.length; index++) {
        sum += Math.pow(data[index] - mean(data), 2);
    }
    return sum;
}

function cov(a, b) {
    var sum = 0;
    for (let index = 0; index < a.length; index++) {
        sum += (a[index] - mean(a)) * (b[index] - mean(b));
    }
    return sum;
}

function SamplePearsonCorrelationCoefficient(a, b) {
    return (cov(a, b)) / (Math.sqrt(var_(a) * var_(b)));
}

var CDEXAM1 = [1.49, 1.09, 0.96, 1.22, 1.24, 1.32, 1.21, 0.99, 0.96, 1.06, 1.02, 1.05, 1.02, 0.96, 1.18, 0.99, 0.98, 1.86, 0.99, 1.15, 1.21, 1.08, 1.06, 0.96];
var IN1 = [10, 7.5, 7.5, 0, 8, 0, 10, 6, 8.5, 0, 8.25, 6.5, 5, 8.5, 0, 5.5, 0, 9, 8.5, 9, 0, 0, 5.5, 0];
var CDEXAM2 = [1.02, 0.99, 0.84, 1.06, 1.02, 1.02, 0.99, 0.99];
var IN2 = [7, 8.25, 8, 8.75, 6.5, 2.25, 7, 4.5];

console.log("Mean");
console.log("CDEXAM1 : ", mean(CDEXAM1));
console.log("IN1 : ", mean(IN1));
console.log("CDEXAM2 : ", mean(CDEXAM2));
console.log("IN2 : ", mean(IN2));
console.log();
console.log("Varience");
console.log("CDEXAM1 : ", var_(CDEXAM1));
console.log("IN1 : ", var_(IN1));
console.log("CDEXAM2 : ", var_(CDEXAM2));
console.log("IN2 : ", var_(IN2));
console.log();
console.log("Covariance between CDEXAM1 and IN1");
console.log(cov(CDEXAM1, IN1));
console.log();
console.log("Covariance between CDEXAM2 and IN2");
console.log(cov(CDEXAM2, IN2));
console.log();
console.log("Sample Pearson Correlation Coefficient between CDEXAM1 and IN1 : ", SamplePearsonCorrelationCoefficient(CDEXAM1, IN1));
console.log("Sample Pearson Correlation Coefficient between CDEXAM2 and IN2 : ", SamplePearsonCorrelationCoefficient(CDEXAM2, IN2));
